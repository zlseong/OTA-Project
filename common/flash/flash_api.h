
#ifndef FLASH_API_H
#define FLASH_API_H
#include <stddef.h>
#include <stdint.h>
#define FLASH_BANK_A 0
#define FLASH_BANK_B 1
int flash_init(void);
int flash_erase_bank(int bank);
int flash_program(int bank, uint32_t offset, const uint8_t* data, size_t len);
int flash_verify_crc(int bank, uint32_t image_size, uint32_t crc32);
int flash_switch_boot_bank(int bank);
#endif

