#ifndef DEFINES_H
# define DEFINES_H
# define HELP_STR "Usage\n"\
"  ping [options] <destination>                                       \n"\
"                                                                     \n"\
"Options:                                                             \n"\
"  <destination>      DNS name or IP address                          \n"\
"  -f                 flood ping                                      \n"\
"  -l <preload>       send <preload> number of packages while waiting replies\n"\
"  -n                 no reverse DNS name resolution, override -H     \n"\
"  -p <pattern>       contents of padding byte                        \n"\
"  -s <size>          use <size> as number of data bytes to be sent   \n"\
"  -t <ttl>           define time to live                             \n"\
"  -v                 verbose output                                  \n"\
"  -V                 print version and exit                          \n"\
"  -w <deadline>      reply wait <deadline> in seconds                \n"\
"  -W <timeout>       time to wait for response                       \n"\
"                                                                     \n"

#define ERROR_STR "ft_ping: usage error: Destination address required\n"

#define VERSION "ft_ping from 42 v0.1.0\n"

#define SHORT_LENGTH 2

#define VERBOSE_STR "ping: sock4.fd: %d (socktype: %s), sock6.fd: -1 (socktype: 0), hints.ai_family: AF_INET\n\n"

#define PING_STR "PING %s (%s) %d\n" 
#endif // !DEFINES_H
