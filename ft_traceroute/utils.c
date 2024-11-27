#include "ft_traceroute.h"

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
        sum += *(uint8_t *)ptr;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}

/**
 * @brief prefroms the dns lookup to find the destination from the
 * address provided by the user
 *
 * @param addr_host
 * @param addr_con
 * @param ip
 */
void dns_lookup(char *addr_host, struct sockaddr_in *addr_con, char *ip)
{
    struct hostent *host_entity;

    host_entity = gethostbyname(addr_host);
    if (!host_entity)
        return;
    char *host = inet_ntoa(*(struct in_addr *)host_entity->h_addr);
    ft_strlcpy(ip, host, ft_strlen(host));
    addr_con->sin_family      = host_entity->h_addrtype;
    addr_con->sin_port        = htons(0);
    addr_con->sin_addr.s_addr = *(long *)host_entity->h_addr;
}

/**
 * @brief Does the reverse dns lookup from the ip address
 *
 * @param ip the ip address populated by dns_lookup
 * @param reverse_ip buffer to put the result
 */
void reverse_dns_lookup(char *ip, char *reverse_ip)
{
    char temp[INET_ADDRSTRLEN] = {0};
    struct sockaddr_in addr_in;
    socklen_t len = sizeof(addr_in);
    ft_memcpy(temp, ip, ft_strlen(ip));
    addr_in.sin_addr.s_addr = inet_addr(temp);
    addr_in.sin_family      = AF_INET;

    getnameinfo((struct sockaddr *)&addr_in, len, reverse_ip, NI_MAXHOST, NULL, 0, NI_NAMEREQD);
}
