
#include <stdio.h>
#include <stdint.h>
int net_connect(const char* host, int port){ printf("[NET] connect to %s:%d (stub)\n", host, port); return 0; }
int net_send(const uint8_t* buf, int len){ printf("[NET] send %d bytes (stub)\n", len); return len; }
int net_recv(uint8_t* buf, int maxlen, int timeout_ms){ (void)buf;(void)maxlen;(void)timeout_ms; printf("[NET] recv (stub)\n"); return 0; }
void net_close(void){ printf("[NET] close (stub)\n"); }

