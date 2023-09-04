/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:58:04 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/23 16:39:14 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_cmds(t_cmd *cmd_lst)
{
	int	count;

	count = 0;
	while (cmd_lst)
	{
		count++;
		cmd_lst = cmd_lst->next;
	}
	return (count);
}

int	**allocate_fds(int count)
{
	int	**fd;
	int	i;

	i = 0;
	fd = malloc((count - 1) * sizeof(*fd));
	if (!fd)
		return (NULL);
	while (i < count - 1)
	{
		fd[i] = malloc(2 * sizeof(**fd)); 
		if (!fd[i++])
			return (free_mem_fd(fd, i), NULL);
	}
	return (fd);
}

int	create_pipes(int **fd, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (pipe(fd[i]) == -1)
			return (perror(" broken pipe\n"), 1);
		i++;
	}
	return (0);
}

void	close_fds(int **fd, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

int	**ft_fds_pipes(int num_cmds)
{
	int	**fd;

	fd = NULL;
	fd = allocate_fds(num_cmds);
	if (!fd)
		return (NULL);
	if (create_pipes(fd, num_cmds))
		return (free_mem_fd(fd, num_cmds), NULL);
	return (fd);
}
