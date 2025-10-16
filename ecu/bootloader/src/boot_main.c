
#include <stdio.h>
#include <stdint.h>
#include "../../common/flash/flash_api.h"
#include "../../common/include/ota_common.h"
#define LOGB(fmt, ...) printf("[ECU-BOOT] " fmt "\n", ##__VA_ARGS__)
static int validate_candidate(void){
    LOGB("validate candidate for %s v%s", OTA_PLATFORM_NAME, OTA_VERSION);
    return 1;
}
int main(void){
    LOGB("start %s v%s", OTA_PLATFORM_NAME, OTA_VERSION);
    if (validate_candidate()){
        LOGB("candidate OK -> switch to BANK_B");
        flash_switch_boot_bank(FLASH_BANK_B);
    } else {
        LOGB("stay on BANK_A");
    }
    return 0;
}

