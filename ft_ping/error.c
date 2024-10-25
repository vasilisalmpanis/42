#include "ft_ping.h"

int error(char *str)
{
    write(2, str, strlen(str));
    return 1;
}
