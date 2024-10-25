#include "ft_ping.h"

void dns_lookup(char *addr_host, struct sockaddr_in *addr_con, char *ip)
{
    struct hostent *host_entity;

    host_entity = gethostbyname(addr_host);
    if (!host_entity)
        return;
    strcpy(ip, inet_ntoa(*(struct in_addr *)host_entity->h_addr));
    addr_con->sin_family      = host_entity->h_addrtype;
    addr_con->sin_port        = htons(0);
    addr_con->sin_addr.s_addr = *(long *)host_entity->h_addr;
}

void reverse_dns_lookup(char *ip, char *reverse_ip)
{
    char temp[INET_ADDRSTRLEN] = {0};
    struct sockaddr_in addr_in;
    socklen_t len = sizeof(addr_in);
    memcpy(temp, ip, strlen(ip));
    addr_in.sin_addr.s_addr = inet_addr(temp);
    addr_in.sin_family      = AF_INET;

    getnameinfo((struct sockaddr *)&addr_in, len, reverse_ip, NI_MAXHOST, NULL, 0, NI_NAMEREQD);
}
