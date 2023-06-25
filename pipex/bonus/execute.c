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
	dup2(object.file[0], STDIN_FILENO);
	if (i != object.argc - 2)
		dup2(object.fd[1], STDOUT_FILENO);
	else
	{
		dup2(object.file[1], STDOUT_FILENO);
	}
	if (execve(object.cmd, object.split, NULL) == -1)
		cmd_not_found(object.split[0]);
}

void	parent_process(t_data object)
{
	int	i;

	close(object.fd[0]);
	close(object.fd[1]);
	close(object.file[1]);
	i = object.argc - 3 - object.here_doc;
	while (--i < 0)
		waitpid(object.pid[i], NULL, 0);
}

void	execute_commands(t_data object)
{
	int	i;

	i = 1 + object.here_doc;
	if (object.file[0] == -1)
		i++;
	while (++i < object.argc - 1)
	{
		if (pipe(object.fd) == -1)
			cmd_failed("pipe");
		object.pid[i - 2 - object.here_doc] = fork();
		object.cmd = find_command(object, i);
		object.split = ft_split(object.argv[i], 26);
		if (object.pid[i - 2 - object.here_doc] == -1)
			cmd_failed("fork");
		if (object.pid[i - 2 - object.here_doc] == 0)
			child_process(object, i);
		close(object.file[0]);
		close(object.fd[1]);
		object.file[0] = object.fd[0];
		free(object.cmd);
		ft_free(object.split);
	}
	parent_process(object);
}
