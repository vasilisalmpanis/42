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
	int	j;

	i = -1;
	j = object->argc - 4 - object->here_doc;
	while (++i < j)
	{
		if (pipe(object->fd[i]) == -1)
			cmd_failed("pipe");
	}
}

void	close_fds(t_data object, int i, int process)
{

}

void	child_process(t_data object, int i, int process)
{
	if (i == 2 + object.here_doc)
	{
		dup2(object.file[READ_END], STDIN_FILENO);
		close(object.file[READ_END]);
		dup2(object.fd[process][WRITE_END], STDOUT_FILENO);
		close(object.fd[process][WRITE_END]);
//		close(object.fd[1][0]);
//		close(object.fd[1][1]);
//		close(object.fd[process][READ_END]);
//		close(object.file[WRITE_END]);
	}
	else if (i == object.argc - 2)
	{
		dup2(object.fd[object.argc -5 - object.here_doc][0], STDIN_FILENO);
		close(object.fd[object.argc -5 - object.here_doc][READ_END]);
		dup2(object.file[WRITE_END], STDOUT_FILENO);
		close(object.file[WRITE_END]);
//		close(object.fd[0][1]);
//		close(object.fd[0][0]);
//		close(object.file[READ_END]);
//		close(object.fd[process - 1][WRITE_END]);
	}
	else
	{
		close(object.file[0]);
		close(object.file[1]);
		close(object.fd[process - 1][1]);
		close(object.fd[process][0]);
//		dup2(object.fd[process - 1][READ_END], STDIN_FILENO);
//		close(object.fd[process - 1][READ_END]);
//		dup2(object.fd[process][WRITE_END], STDOUT_FILENO);
//		close(object.fd[process][WRITE_END]);
	}
	if (execve(object.cmd, object.split, NULL) == -1)
		cmd_not_found(object.split[0]);
}

void	parent_process(t_data object)
{
	int	i;

	i = -1;
	while (++i < object.argc - 4 - object.here_doc)
	{
		close(object.fd[i][READ_END]);
		close(object.fd[i][WRITE_END]);
	}
	close(object.file[0]);
	close(object.file[1]);
	i = object.argc - 3 - object.here_doc;
	while (--i < 0)
		waitpid(object.pid[i], NULL, 0);
}

void	execute_commands(t_data object)
{
	int	i;
	int process;

	pipes(&object);
	i = 1 + object.here_doc;
	if (object.file[0] == -1)
		i++;
	process = 0;
	while (++i < object.argc - 1)
	{
		object.pid[i - 2 - object.here_doc] = fork();
		object.cmd = find_command(object, i);
		object.split = ft_split(object.argv[i], 26);
		if (object.pid[i - 2 - object.here_doc] == -1)
			cmd_failed("fork");
		if (object.pid[i - 2 - object.here_doc] == 0)
			child_process(object, i, process);
		free(object.cmd);
		ft_free(object.split);
		process++;
	}
	parent_process(object);
}
