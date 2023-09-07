/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:30:34 by valmpani          #+#    #+#             */
/*   Updated: 2023/09/05 08:09:16 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_make_new(char *rest, char *buf)
{
	char	*temp;

	temp = ft_strjoin(rest, buf);
	free(rest);
	return (temp);
}

char	*ft_line_rest(char *rest)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		ft_bzero(rest, ft_strlen(rest));
		free(rest);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(rest) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (rest[i])
		line[j++] = rest[i++];
	line[j] = '\0';
	ft_bzero(rest, ft_strlen(rest));
	free(rest);
	return (line);
}

char	*ft_line(char *rest)
{
	int		i;
	char	*line;

	i = 0;
	if (ft_strlen(rest) == 0)
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] && rest[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *rest)
{
	char	*buf;
	int		bytes;

	if (!rest)
		rest = ft_calloc(1, sizeof(char));
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(rest);
			free(buf);
			return (NULL);
		}
		buf[bytes] = 0;
		rest = ft_make_new(rest, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (rest);
}

char *get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_read_file(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_line(rest);
	rest = ft_line_rest(rest);
	return (line);
}


// int main()
// {
// 	char *name = "read_error.txt";
// 	int fd = open(name, O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	fd = open(name, O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
