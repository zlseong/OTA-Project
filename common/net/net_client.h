
#ifndef NET_CLIENT_H
#define NET_CLIENT_H
#include <stdint.h>
int net_connect(const char* host, int port);
int net_send(const uint8_t* buf, int len);
int net_recv(uint8_t* buf, int maxlen, int timeout_ms);
void net_close(void);
#endif

