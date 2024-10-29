#ifndef DEFINES_H
#define DEFINES_H

#define ARGS_DOC  "HOST ..."
#define DOC "Send ICMP_REQUEST packets to network hosts"

#define ERROR_STR "ft_ping: usage error: Destination address required\n"

#define VERSION "ft_ping from 42 v0.1.0\n"

#define SHORT_LENGTH 2

#define VERBOSE_STR \
    "ping: sock4.fd: %d (socktype: %s), sock6.fd: -1 (socktype: 0), hints.ai_family: AF_INET\n\n"

#define PING_STR "PING %s (%s) 56 data bytes"

#define success_format_string "%lu bytes from %s (%s): icmp_seq=%d ttl=%d time=%.3f ms\n"
#define success_format_string2 "%lu bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n"
#define failure_format_string "From %s (%s) icmp_seq=%d %s\n"
#define failure_format_string2 "From %s icmp_seq=%d %s\n"
#define RTT_STR "\nround-trip min/avg/max/stddev = %ld.%03ld/%lu.%03ld/%ld.%03ld/%ld.%03ld ms"

#endif  // !DEFINES_H
