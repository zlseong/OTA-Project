
#include <stdio.h>
#include <stdint.h>
#include "../include/ota_common.h"
#include "flash_api.h"
int flash_init(void){ printf("[FLASH] init\n"); return 0; }
int flash_erase_bank(int bank){ printf("[FLASH] erase bank=%d\n", bank); return 0; }
int flash_program(int bank, uint32_t offset, const uint8_t* data, size_t len){ (void)data; printf("[FLASH] program bank=%d offset=%u len=%zu\n", bank, offset, len); return 0; }
int flash_verify_crc(int bank, uint32_t image_size, uint32_t crc32){ printf("[FLASH] verify bank=%d size=%u crc=0x%08X -> OK (stub)\n", bank, image_size, crc32); return 1; }
int flash_switch_boot_bank(int bank){ printf("[FLASH] switch boot bank -> %d (stub)\n", bank); return 0; }

