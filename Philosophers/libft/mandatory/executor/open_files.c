/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:45:22 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/23 15:46:09 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	open_files(t_cmd *cmd, int **fd)
{
	int	*fd_in_out;
	int	flag;

	flag = cmd->hd_last;
	fd_in_out = open_in_out_files(cmd->file);
	if (!fd_in_out)
		return (unlink(cmd->hd_file), 1);
	if (set_stdin(flag, fd_in_out, cmd, fd))
		return (free(fd_in_out), 1);
	if (set_stdout(fd_in_out, fd, cmd))
		return (free(fd_in_out), 1);
	free(fd_in_out);
	return (0);
}

int	*open_in_out_files(t_file *file_lst)
{
	int	*fd_temp;

	fd_temp = ft_calloc(2, sizeof(*fd_temp));
	if (!fd_temp)
		return (NULL);
	while (file_lst)
	{
		if (open_in_out_files_helper(file_lst, fd_temp))
			return (free(fd_temp), NULL);
		file_lst = file_lst->next;
	}
	return (fd_temp);
}

int	open_in_out_files_helper(t_file *file_lst, int	*fd_temp)
{
	if (file_lst->token == TK_IN_R)
	{
		if (fd_temp[IN] != 0)
			close(fd_temp[IN]);
		fd_temp[IN] = open_in_file(file_lst);
		if (fd_temp[IN] == -1)
			return (1);
	}
	if (file_lst->token == TK_OUT_R || file_lst->token == TK_APP_R)
	{
		if (fd_temp[OUT] != 0)
			close(fd_temp[OUT]);
		fd_temp[OUT] = open_out_file(file_lst);
		if (fd_temp[OUT] == -1)
			return (1);
	}
	return (0);
}

int	open_in_file(t_file *file)
{
	int	fd;

	fd = open(file->name, O_RDONLY);
	if (fd == -1)
	{
		perror(file->name);
		return (-1);
	}
	return (fd);
}

int	open_out_file(t_file *file)
{
	int	fd_temp;

	fd_temp = 0;
	if (file->token == TK_OUT_R)
		fd_temp = open(file->name, O_RDWR | O_CREAT | O_TRUNC, 00644);
	else
		fd_temp = open(file->name, O_RDWR | O_CREAT | O_APPEND, 00644);
	if (fd_temp == -1)
	{
		perror(file->name);
		return (-1);
	}
	return (fd_temp);
}
