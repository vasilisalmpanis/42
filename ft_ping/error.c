#include "ft_ping.h"

/**
 * @brief Prints error to STDERR
 *
 * @param str the string to print
 * @return 1
 */
int error(char *str)
{
    write(2, str, strlen(str));
    return 1;
}
