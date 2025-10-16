#ifndef OTA_COMMON_H
#define OTA_COMMON_H
#include <stdint.h>
#include <stddef.h>
#define OTA_PLATFORM_NAME "OTA_platform_TC375"
#define OTA_VERSION       "0.0.0"
#ifdef __cplusplus
extern "C" {
#endif
#define OTA_MAGIC 0x4F544131u
#define OTA_MAX_VIN_LEN 17
#define OTA_TARGET_CCU  1
#define OTA_TARGET_ZG   2
#define OTA_TARGET_ECU  3
typedef enum { OTA_ROLE_CCU, OTA_ROLE_ZG, OTA_ROLE_ECU } ota_role_t;
typedef enum { OTA_MSG_META=0x01, OTA_MSG_CHUNK=0x02, OTA_MSG_APPLY=0x03, OTA_MSG_STATUS=0x04 } ota_msg_type_t;
typedef struct { char vin[OTA_MAX_VIN_LEN + 1]; uint8_t target; char version[16]; uint32_t total_size; uint32_t crc32; } ota_meta_t;
typedef struct { uint32_t received; uint32_t expected; } ota_progress_t;
int ota_on_meta(const ota_meta_t* m);
int ota_on_chunk(const uint8_t* data, size_t len, uint32_t offset);
int ota_on_apply(void);
#ifdef __cplusplus
}
#endif
#endif
