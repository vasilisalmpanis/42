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
 * @brief Option parsing function
 *
 * @param key
 * @param arg
 * @param state
 * @return
 */
int parse_opt(int key, char *arg, struct argp_state *state)
{
    (void)arg;
    (void)state;
    switch (key) {
        case 'v':
            settings.verbose = true;
            break;
        case 'V':
            error(VERSION);
            exit(0);
        case 'H':
            settings.no_dns = false;
            break;
        case 's':
            // TODO
            break;
        case 't':
            is_num(arg);
            settings.ttl = atoi(arg);
            if (settings.ttl == 0) {
                printf("ft_ping: option value too small: 0");
                exit(1);
            } else if (settings.ttl > 255) {
                printf("ft_ping: option value too big: 0");
                exit(1);
            }
        case 'w':
            // TODO
            break;
        case 'W':
            // TODO
            break;
        case 'l':
            is_num(arg);
            settings.preload = atoi(arg);
            break;
        case 'c':
            is_num(arg);
            settings.npackets = atoi(arg);
            break;
        case 'i':
            is_num(arg);
            settings.interval *= atoi(arg);
            if (settings.interval > 2147483) {
                printf("ping: bad timing interval: %d\n", settings.interval);
                exit(1);
            }
        case ARGP_KEY_ARG:
            if (settings.target)
                return ARGP_ERR_UNKNOWN;
            settings.target = arg;
            settings.is_ip  = isValidIpAddress(arg);
            return 0;  // Handle positional arguments here if needed
        case ARGP_KEY_END:
            if (!settings.target) {
		error(ERROR_STR);
                exit(1);
            }
            return 0;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}
