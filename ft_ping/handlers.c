#include "ft_ping.h"

/**
 * @brief Helper to check if opt is a valid number
 *
 * @param arg opt buffer
 * @return 0 if a positive decimal number else exits
 */
int is_num(char *arg)
{
    bool minus = false;
    for (int i = 0; arg[i]; i++) {
        if (arg[i] == '-' && !minus)
            minus = true;
        else if (arg[i] < '0' || arg[i] > '9')
            return (1);
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
    (void)state;
    uint32_t num;
    // Could implement flood but not necessary already have interval which can work like flood
    // but with normal output not dots.
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
        case 't':
            if (is_num(arg)) {
                printf("%s: invalid value ('%s' near '%s')\n", settings.argv[0], arg, arg);
                return 1;
            }
            settings.ttl = (uint32_t)atoi(arg);
            if (settings.ttl == 0) {
                printf("ft_ping: option value too small: 0");
                exit(1);
            } else if (settings.ttl > 255) {
                printf("ft_ping: option value too big: 0");
                exit(1);
            }
        case 'w':
	    if (is_num(arg)) {
                printf("%s: invalid value ('%s' near '%s')\n", settings.argv[0], arg, arg);
                return 1;
            }
	    num = atoi(arg);
	    if (num > 2147483) {
                printf("ping: bad timing interval: %d\n",num); 
		return 1;
            }
	    settings.deadline.tv_sec = num;
            break;
        case 'l':
            if (is_num(arg)) {
                printf("%s: invalid value ('%s' near '%s')\n", settings.argv[0], arg, arg);
                return 1;
            }
            settings.preload = atoi(arg);
            break;
        case 'c':
            if (is_num(arg)) {
                printf("%s: invalid value ('%s' near '%s')\n", settings.argv[0], arg, arg);
                return 1;
            }
            settings.npackets = atoi(arg);
            break;
        case 'i':
            is_num(arg);
	    num = (uint32_t)atoi(arg);
            settings.interval *= atoi(arg);
            if (num > 2147483) {
                printf("ping: bad timing interval: %d\n",num); 
                exit(1);
            }
	    return 0;
        case ARGP_KEY_ARG:
            if (settings.target)
                return ARGP_ERR_UNKNOWN;
            settings.target = arg;
            settings.is_ip  = isValidIpAddress(arg);
            return 0;  // Handle positional arguments here if needed
        case ARGP_KEY_END:
            if (!settings.target) {
                printf("%s: missing host operand\n", settings.argv[0]);
                return 1;
            }
            return 0;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}
