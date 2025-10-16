
#include <stdio.h>
#include <stdint.h>
#include "../../common/include/ota_common.h"
#define LOG(fmt, ...) printf("[ECU-APP] " fmt "\n", ##__VA_ARGS__)
static void app_init(void){ LOG("init %s v%s", OTA_PLATFORM_NAME, OTA_VERSION); }
static void app_loop(void){ LOG("loop once and exit (template)"); }
int main(void){
    app_init();
    ota_meta_t m = {"VIN12345678901234", 3, OTA_VERSION, 1024, 0xDEADBEEF};
    ota_on_meta(&m);
    unsigned char d[256] = {0};
    for(int i=0;i<4;i++) ota_on_chunk(d, sizeof(d), i*256);
    ota_on_apply();
    app_loop();
    return 0;
}

