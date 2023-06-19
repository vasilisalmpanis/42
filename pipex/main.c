/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:46:50 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 11:54:53 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	object;

	if (argc != 5)
	{
		ft_printf("file1 cmd cmd file2\n");
		return (-1);
	}
	object.argc = argc;
	object.argv = argv;
	object.env = env;
	object.file_fd[0] = has_access(object);
	if (object.file_fd[0] == -1)
	{
		ft_printf("Pipex: ");
		perror(object.argv[1]);
	}
	object.file_fd[1] = open(object.argv[argc - 1], O_WRONLY, O_TRUNC, O_CREAT, 0777);
	if (object.file_fd[1] == -1)
	return (0);
}
