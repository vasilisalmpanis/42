#include "get_next_line.h"

int main()
{
    char buf[3][10] = {"text1", "text2", "test3"};
    int fd;
    int i;
    int j = -1;
    char *line;

    while (++j < 3)
    {
        i = -1;
        fd = open(buf[j],O_RDONLY);
        while (++i < 8)
        {
            line = get_next_line(fd);
            printf("%s", line);
            free(line);
        }
        printf("\n");
        close(fd);
    }
    return (0);
}