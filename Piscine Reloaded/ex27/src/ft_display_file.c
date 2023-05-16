/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:08:36 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/10 17:15:06 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ft.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	bu[1024];
	int		fd;
	int		bytes;

	if (argc == 1)
	{
		write(1, "File name missing.\n", 20);
	}
	else if (argc > 2)
	{
		write(1, "Too many arguments.\n", 21);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(1, "Cannot read file.\n", 19);
		}
		bytes = read(fd, bu, 1024);
		write(1, &bu, bytes);
	}
}
