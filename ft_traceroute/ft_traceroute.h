#ifndef FT_TRACEROUTE
#define FT_TRACEROUTE

#include <argp.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "defines.h"
#include "libft/libft.h"
struct sock {
    int fd;
    int type;
};

struct opts {
    char *intf;
    char *host;

    int max_ttl;
    int current_ttl;

    struct sock socket;
    bool verbose;

};
#endif  // !FT_TRACEROUTE
