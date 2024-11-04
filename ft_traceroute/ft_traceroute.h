#ifndef FT_TRACEROUTE
#define FT_TRACEROUTE

#include <argp.h>
#include <stdio.h>
#include <unistd.h>

#include "defines.h"
#include "libft/libft.h"
#include "stdbool.h"

struct opts {
    int max_ttl;
    bool verbose;
};
#endif  // !FT_TRACEROUTE
