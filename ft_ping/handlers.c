#include "defines.h"
#include "ft_ping.h"

/**
 * @brief Helper to check if opt is a valid number
 *
 * @param arg opt buffer
 * @return 0 if a positive decimal number else exits
 */
int is_num(char *arg)
{
    for (int i = 0; arg[i]; i++) {
        if (arg[i] < '0' || arg[i] > '9')
            exit(1);
        // TODO fix this in case of error
    }
    return 0;
}

/**
 * @brief Sets the interval between each consecutive sendto
 *
 * @return how many args we should advance
 */
int interval_handler()
{
    if (settings.option == settings.argc - 1) {
        error("Invalid Option\n");
        exit(1);
    }
    if (is_num(settings.argv[settings.option + 1])) {
        printf("ping: please provide a valid interval\n");
        exit(1);
    }
    int interval = atoi(settings.argv[settings.option + 1]);
    settings.interval *= interval;
    if (interval > 2147483) {
        printf("ping: bad timing interval: %d\n", settings.interval);
        exit(1);
    }
    return 2;
}

/**
 * @brief Sets the preload parameter
 *
 * @return how many args we should advance
 */
int preload_handler()
{
    if (settings.option == settings.argc - 1) {
        error("Invalid Option\n");
        exit(1);
    }
    if (is_num(settings.argv[settings.option + 1])) {
        printf("ping: please provide a valid number for reps\n");
        exit(1);
    }
    settings.preload = atoi(settings.argv[settings.option + 1]);
    if (settings.preload > 2147483) {
        printf("ping: bad timing interval: %d\n", settings.preload);
        exit(1);
    }
    return 2;
}

/**
 * @brief Sets the no_dns opt to false so
 * we perform reverse_dns on the ip address
 *
 * @return the amount of args to advance
 */
int dns_handler()
{
    settings.no_dns = false;
    return 1;
}

/**
 * @brief Prints the help str
 *
 * @return
 */
int help_handler()
{
    error(HELP_STR);
    return 1;
}

/**
 * @brief Prints version and exits
 *
 * @return
 */
int version_handler()
{
    error(VERSION);
    exit(0);
    return 1;
}

/**
 * @brief Sets verbose level to true
 *
 * @return
 */
int verbose_handler()
{
    settings.verbose = true;
    return 1;
}

/**
 * @brief Sets the total amount of ping packets to send
 *
 * @return the amount of argcs to advance
 */
int count_handler()
{
    if (settings.option == settings.argc - 1) {
        error("Invalid Option\n");
    }
    if (is_num(settings.argv[settings.option + 1])) {
        printf("ping: please provide a valid number for reps\n");
        exit(1);
    }
    long packet_num   = strtol(settings.argv[settings.option + 1], NULL, 10);
    settings.npackets = packet_num;
    return 2;
}

/**
 * @brief Sets the ttl parameter for the number of allowed 'hops'
 *
 * @return the amount of argcs to advance
 */
int ttl_handler()
{
    if (settings.option == settings.argc - 1) {
        error("Invalid Option\n");
        exit(1);
    }
    int ttl      = atoi(settings.argv[settings.option + 1]);
    settings.ttl = ttl;
    return 2;
}
