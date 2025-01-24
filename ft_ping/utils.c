#include "ft_ping.h"

/**
 * @brief The square root of long long
 *
 * @param a the number
 * @return the square root of a casted to long
 */
long llsqrt(long long a)
{
    long long prev = LLONG_MAX;
    long long x    = a;

    if (x > 0) {
        while (x < prev) {
            prev = x;
            x    = (x + (a / x)) / 2;
        }
    }

    return (long)x;
}

/**
 * @brief Checks if the address is valid
 *
 * @param ipAddress  the address to check
 * @return true if is valid else false
 */
bool isValidIpAddress(char *ipAddress)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return result != 0;
}

/**
 * @brief Debugging function to print hex content of
 * a packet like hexdump
 *
 * @param packet the raw packet in bytes
 * @param length the length of the packet to print
 */
void print_packet_hex(uint8_t *packet, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%02x ", packet[i]);
        // Print a newline every 16 bytes (for formatting)
        if ((i + 1) % 8 == 0)
            printf(" ");
        if ((i + 1) % 16 == 0) {
            printf("   ");
            // Print the ASCII representation of the bytes
            for (int j = i - 15; j <= i; j++) {
                // Print '.' for non-printable characters
                printf("%c", isprint(packet[j]) ? packet[j] : '.');
            }
            printf("\n");
        }
    }

    // Print any remaining bytes if the total isn't a multiple of 16
    if (length % 16 != 0) {
        int padding = 16 - (length % 16);
        for (int i = 0; i < padding; i++) {
            printf("   ");  // Add space for the remaining columns
        }

        // Print the ASCII part for remaining bytes
        printf("     ");  // Add space for the remaining columns
        for (int i = length - (length % 16); i < length; i++) {
            printf("%c", isprint(packet[i]) ? packet[i] : '.');
        }
        printf("\n");
    }
}

void print_ip_header(struct iphdr *iph) {
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(iph->saddr), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(iph->daddr), dst_ip, INET_ADDRSTRLEN);

    unsigned char *ptr = (unsigned char *)iph;
    printf("IP Hdr Dump:\n ");
    for (int i = 0; i < 20; i++) {
        printf("%02x", ptr[i]);
        if ((i + 1) % 2 == 0) printf(" ");
    }
    printf("\n");

    printf("Vr HL TOS  Len   ID Flg  off TTL Pro  cks      Src\tDst\tData\n");
    printf(" %1x  %1x  %02x %04x %04x   %1x %04x  %02x  %02x %04x %s  %s\n",
        iph->version,
        iph->ihl,
        iph->tos,
        ntohs(iph->tot_len),
        ntohs(iph->id),
        (ntohs(iph->frag_off) >> 13),
        ntohs(iph->frag_off) & 0x1FFF,
        iph->ttl,
        iph->protocol,
        ntohs(iph->check),
        src_ip,
        dst_ip);
}

void print_icmp_header(struct icmphdr *icmph) {
    printf("ICMP: type %d, code %d, size 64, id 0x%04x, seq 0x%04x\n",
        icmph->type,
        icmph->code,
        ntohs(icmph->un.echo.id),
        ntohs(icmph->un.echo.sequence));
}
