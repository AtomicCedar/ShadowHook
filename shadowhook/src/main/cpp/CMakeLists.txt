cmake_minimum_required(VERSION 4.0.2)
project(shadowhook C CXX ASM)

if(${ANDROID_ABI} STREQUAL "arm64-v8a")
    set(ARCH "arm64")
    set(ARCH_LINK_FLAGS "-Wl,-z,max-page-size=16384")
elseif(${ANDROID_ABI} STREQUAL "armeabi-v7a")
    set(ARCH "arm")
    set(ARCH_LINK_FLAGS "")
endif()

set(TARGET "shadowhook")
file(GLOB SRC *.c *.cc arch/${ARCH}/*.c arch/${ARCH}/*.S common/*.c)
add_library(${TARGET} SHARED
    ${SRC}
    third_party/xdl/xdl/src/main/cpp/xdl_iterate.c
    third_party/xdl/xdl/src/main/cpp/xdl_linker.c
    third_party/xz-embedded/linux/lib/xz/xz_crc32.c
    third_party/xz-embedded/linux/lib/xz/xz_dec_lzma2.c
    third_party/xz-embedded/linux/lib/xz/xz_dec_stream.c
)
set_target_properties(${TARGET} PROPERTIES C_STANDARD 11 CXX_STANDARD 20)
target_compile_options(${TARGET} PRIVATE -Weverything)
target_include_directories(${TARGET} PRIVATE
    .
    include
    arch/${ARCH}
    common
    third_party/xdl/xdl/src/main/cpp/include
    third_party/xdl/xdl/src/main/cpp
    third_party/bsd
    third_party/lss
    third_party/xz-embedded/linux/include/linux
    third_party/xz-embedded/userspace
)
target_link_libraries(${TARGET} log)
target_link_options(${TARGET} PRIVATE ${ARCH_LINK_FLAGS})
if(USEASAN)
    target_compile_options(${TARGET} PRIVATE -fsanitize=address -fno-omit-frame-pointer)
    target_link_options(${TARGET} PRIVATE -fsanitize=address)
else()
    target_compile_options(${TARGET} PRIVATE -Os -ffunction-sections -fdata-sections)
    target_link_options(${TARGET} PRIVATE -Os -Wl,--exclude-libs,ALL -Wl,--gc-sections -Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/shadowhook.map.txt)
endif()
if(CMAKE_BUILD_TYPE MATCHES "^(Release|RelWithDebInfo)$")
    target_compile_options(${TARGET} PRIVATE
        -Oz
        -flto
        -fdata-sections
        -ffunction-sections
        -fno-stack-protector
        -U_FORTIFY_SOURCE
    )
    target_link_options(${TARGET} PRIVATE
        -Wl,--as-needed
        -Wl,--gc-sections
        -Wl,--icf=all
    )
endif()