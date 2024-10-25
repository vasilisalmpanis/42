#include "ft_ping.h"

unsigned short icmp_checksum(void *packet, size_t length)
{
    uint32_t sum    = 0;
    uint32_t answer = 0;
    uint16_t *ptr   = (unsigned short *)packet;
    while (length > 1)
    {
        sum += *(ptr++);
        length -= 2;
    }
    if (length == 1)
        sum = *(uint8_t *)ptr;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}
