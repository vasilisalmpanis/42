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

int	execute_commands(t_data object)
{
	int	i;
	int j;

	j = -1;
	dup2(object.file[0], STDIN_FILENO);
	close(object.file[0]);
	if (pipe(object.fd) == -1)
	{
		ft_printf("Pipe\n");
		exit(1);
	}
	i = 1;
	object.split = split_args(object, i + 1);
	object.cmd = find_command(object, i + 1);
	execve(object.cmd, object.split, NULL);
	// while (++i < object.argc -1)
	// {
	// }
	return (1);
}

// int	execute_commands(t_data object)
// {
// 	int	i;
// 	dup2(object.file[0], STDIN_FILENO);
// 	close(object.file[0]);
// 	if (pipe(object.fd) == -1)
// 	{
// 		ft_printf("Pipe\n");
// 		exit(1);
// 	}
// 	i = 1;
// 	while (++i < object.argc -1)
// 	{
// 		object.cmd;
// 		object.split;
// 		object.pid[i - 2] = fork();
// 		if (object.pid[i - 2] == -1)
// 		{
// 			ft_printf("Error\n");
// 			exit(1);
// 		}
// 		if (object.pid[i - 2] == 0)
// 			child_process(object, i);
// 	}
// 	i = 1;
// 	while (++i < object.argc -1)
// 		parent_process(object);
// 	close(object.file[1]);
// }