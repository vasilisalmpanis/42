/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:58:14 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 17:27:18 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_data object, int i)
{
	if (i == 2)
	{
		dup2(object.file[0], STDIN_FILENO);
		close(object.fd[0]);
		close(object.file[0]);
		dup2(object.fd[1], STDOUT_FILENO);
		close(object.fd[1]);
	}
	else
	{
		close(object.file[0]);
		close(object.fd[1]);
		dup2(object.fd[0], STDIN_FILENO);
		close(object.fd[0]);
		dup2(object.file[1], STDOUT_FILENO);
		close(object.file[1]);
	}
	if (execve(object.cmd, object.split, NULL) == -1)
	{
		exit (1);
	}
}

int	execute_commands(t_data object)
{
	int	i;

	if (pipe(object.fd) == -1)
	{
		ft_printf("Pipe\n");
		exit(1);
	}
	i = 1;
	while (++i < object.argc -1)
	{
		object.cmd = find_command(object, i);
		object.split = ft_split(object.argv[i], 26);
		object.pid[i - 2] = fork();
		if (object.pid[i - 2] == -1)
		{
			ft_printf("Error\n");
			exit(1);
		}
		if (object.pid[i - 2] == 0)
			child_process(object, i);
		free(object.cmd);
		ft_free(object.split);
	}
	close(object.fd[0]);
	close(object.fd[1]);
	close(object.file[0]);
	close(object.file[1]);
	waitpid(object.pid[0], NULL, 0);
	waitpid(object.pid[1], NULL, 0);
	return (0);
}
