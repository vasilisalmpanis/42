#include "ft_ping.h"

long llsqrt(long long a)
{
	long long prev = LLONG_MAX;
	long long x = a;

	if (x > 0) {
		while (x < prev) {
			prev = x;
			x = (x + (a / x)) / 2;
		}
	}

	return (long)x;
}

bool isValidIpAddress(char *ipAddress)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return result != 0;
}

void print_packet_hex(uint8_t *packet, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x ", packet[i]);
        // Print a newline every 16 bytes (for formatting)
	if ((i + 1) % 8 == 0)
		printf(" ");
        if ((i + 1) % 16 == 0) {
            printf("   ");
            // Print the ASCII representation of the bytes
            for (int j = i - 15; j <= i; j++) {
                // Print '.' for non-printable characters
                printf("%c", isprint(packet[j]) ? packet[j] : '.');
            }
            printf("\n");
        }
    }

    // Print any remaining bytes if the total isn't a multiple of 16
    if (length % 16 != 0) {
        int padding = 16 - (length % 16);
        for (int i = 0; i < padding; i++) {
            printf("   "); // Add space for the remaining columns
        }

        // Print the ASCII part for remaining bytes
        printf("     "); // Add space for the remaining columns
        for (int i = length - (length % 16); i < length; i++) {
            printf("%c", isprint(packet[i]) ? packet[i] : '.');
        }
        printf("\n");
    }
}
