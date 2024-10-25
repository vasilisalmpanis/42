#include "ft_ping.h"

/**
 * @brief Calculates the checksum of the icmp packet
 *
 * The 16 bit one's complement of the one's complement sum of all 16
 *   bit words in the header.  For computing the checksum, the checksum
 *    field should be zero.  This checksum may be replaced in the
 *    future.
 * @param packet the raw packet as bytes
 * @param length the length of the bytes
 * @return the checksum as unsigned short
 */
unsigned short icmp_checksum(void *packet, size_t length)
{
    uint32_t sum    = 0;
    uint32_t answer = 0;
    uint16_t *ptr   = (unsigned short *)packet;
    while (length > 1) {
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
