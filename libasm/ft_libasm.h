#ifndef LIBASM
# define LIBASM
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>

size_t	ft_strlen(char *buf);
char	*ft_strcpy(char *restrict dst, const char *restrict src);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_write(int fd, char *buff, size_t length);
size_t	ft_read(int fd, char *buff, size_t length);
char	*ft_strdup(char *str);
#endif // !LIBASM
