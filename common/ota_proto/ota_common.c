
#include <stdio.h>
#include <string.h>
#include "../include/ota_common.h"
static ota_meta_t g_meta;
static ota_progress_t g_prog;
int ota_on_meta(const ota_meta_t* m){
    g_meta = *m;
    g_prog.received = 0; g_prog.expected = m->total_size;
    printf("[OTA] META vin=%s ver=%s size=%u crc=0x%08X\n", g_meta.vin, g_meta.version, g_meta.total_size, g_meta.crc32);
    return 0;
}
int ota_on_chunk(const uint8_t* data, size_t len, uint32_t offset){
    (void)data; (void)offset;
    if (g_prog.received + len > g_prog.expected) len = g_prog.expected - g_prog.received;
    g_prog.received += (uint32_t)len;
    printf("[OTA] CHUNK off=%u len=%zu progress=%u/%u\n", offset, len, g_prog.received, g_prog.expected);
    return 0;
}
int ota_on_apply(void){
    printf("[OTA] APPLY requested -> will switch bank on ignition-off (stub)\n");
    return 0;
}

