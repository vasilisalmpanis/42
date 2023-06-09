/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:58:14 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/28 12:33:20 by valmpani         ###   ########.fr       */
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
		if (dup2(object.file[1], STDOUT_FILENO) == -1)
			exit(0);
		close(object.file[1]);
	}
	if (execve(object.cmd, object.split, NULL) == -1)
		cmd_not_found(object.split[0]);
}

void	parent_process(t_data object)
{
	int	status_code1;
	int	status_code2;

	close(object.fd[0]);
	close(object.fd[1]);
	close(object.file[0]);
	close(object.file[1]);
	waitpid(object.pid[0], &status_code1, 0);
	waitpid(object.pid[1], &status_code2, 0);
	if (status_code1 >> 8 && !(status_code2 >> 8))
		exit(status_code1 >> 8);
	exit(status_code2 >> 8);
}

void	execute_commands(t_data object)
{
	int	i;

	if (pipe(object.fd) == -1)
		cmd_failed("pipe");
	i = 1;
	if (object.file[0] == -1)
		i++;
	while (++i < object.argc -1)
	{
		object.cmd = find_command(object, i);
		object.split = ft_split(object.argv[i], 26);
		object.pid[i - 2] = fork();
		if (object.pid[i - 2] == -1)
			cmd_failed("fork");
		if (object.pid[i - 2] == 0)
			child_process(object, i);
		free(object.cmd);
		ft_free(object.split);
	}
	parent_process(object);
}
