#ifndef FT_TRACEROUTE
#define FT_TRACEROUTE

#include <argp.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/ip_icmp.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>

#include "defines.h"
#include "libft/libft.h"
struct sock {
    int fd;
    int type;
};

struct packet {
    struct icmphdr icmp;
    uint8_t *buf;
};

struct opts {
    char *intf;
    char *host;

    int max_ttl;
    int current_ttl;

    struct sock socket;
    bool verbose;
    size_t packetlen;

    struct packet packet;
};

unsigned short icmp_checksum(void *packet, size_t length);
#endif  // !FT_TRACEROUTE
