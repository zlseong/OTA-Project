
#ifndef OTA_IMAGE_HEADER_H
#define OTA_IMAGE_HEADER_H
#include <stdint.h>
#define OTA_IMG_MAGIC 0x4F544149u
typedef struct __attribute__((packed)) {
    uint32_t magic, header_size, image_size, crc32;
    uint32_t version_major, version_minor, version_patch;
    uint32_t sig_offset, sig_size;
} ota_image_header_t;
#endif

