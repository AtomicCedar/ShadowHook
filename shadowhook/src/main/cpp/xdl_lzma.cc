#include "xdl_lzma.h"

#include <link.h>
#include <stdlib.h>

#include "xz.h"

int xdl_lzma_decompress(uint8_t *src, size_t src_size, uint8_t **dst, size_t *dst_size) {
  static constexpr size_t kBufferSize = 2 * 1024 * 1024;

  static bool crc32_initialized_{};
  if (!crc32_initialized_) {
    xz_crc32_init();
    crc32_initialized_ = true;
  }

  auto deflater = xz_dec_init(XZ_DYNALLOC, 1 << 26);

  auto out = static_cast<uint8_t *>(malloc(kBufferSize));
  int out_size = kBufferSize;

  struct xz_buf buf{
      .in = src, .in_pos = 0, .in_size = src_size, .out = out, .out_pos = 0, .out_size = kBufferSize};

  uint8_t skip = 0;

  for (auto ret = XZ_OK;;) {
    ret = xz_dec_run(deflater, &buf);

    if (buf.out_pos == kBufferSize) {
      buf.out_pos = 0;
      ++skip;
    } else {
      out_size -= (kBufferSize - buf.out_pos);
    }

    if (ret == XZ_OK) {
      out_size += kBufferSize;
      out = static_cast<uint8_t *>(realloc(out, out_size));
      buf.out = out + (skip * kBufferSize);
      continue;
    }

    if (ret == XZ_UNSUPPORTED_CHECK) [[unlikely]] {
      continue;
    }

    xz_dec_end(deflater);
    if (ret != XZ_STREAM_END) [[unlikely]] {
      free(out);
      return -1;
    } else {
      break;
    }
  }

  if (auto magic = *reinterpret_cast<uint32_t *>(out); out_size <= sizeof(ElfW(Ehdr)) || magic != 0x464C457FU)
      [[unlikely]] {
    free(out);
    return -1;
  }

  *dst = out;
  if (dst_size) *dst_size = out_size;
  return 0;
}
