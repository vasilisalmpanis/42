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

void	pipes(t_data *object)
{
	int	i;

	i = -1;
	while (++i < (object->argc - 2 + object->here_doc))
		if (pipe(object->fd[i]) == -1)
			cmd_failed("pipe");
}

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

	pipes(&object);
	i = 1 + obje;
	if (object.file[0] == -1)
		i++;
	while (++i < object.argc -1)
	{
		object.pid[i - 2] = fork();
		object.cmd = find_command(object, i);
		object.split = ft_split(object.argv[i], 26);
		if (object.pid[i - 2] == -1)
			cmd_failed("fork");
		if (object.pid[i - 2] == 0)
			child_process(object, i);
		free(object.cmd);
		ft_free(object.split);
	}
	parent_process(object);
}
