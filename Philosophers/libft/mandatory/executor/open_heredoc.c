/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:09:47 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/23 11:29:02 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_heredoc_name(int *i, t_cmd *cmd_lst)
{
	char	*buf;

	buf = ft_itoa((*i)++);
	if (!buf)
		return (1);
	cmd_lst->hd_file = ft_strjoin(HEREDOC, buf);
	free(buf);
	return (0);
}

int	open_heredocs(t_cmd *cmd_lst, t_env *lst, int i)
{
	t_file	*start_files;

	while (cmd_lst)
	{
		cmd_lst->hd_last = -1;
		if (ft_heredoc_name(&i, cmd_lst))
			return (1);
		start_files = cmd_lst->file;
		while (start_files)
		{
			if (start_files->token == TK_HERE_DOC)
			{
				if (heredoc(cmd_lst, start_files, lst))
					return (1);
				cmd_lst->hd_last = 0;
			}
			if (start_files->token == TK_IN_R)
				cmd_lst->hd_last = 1;
			start_files = start_files->next;
		}
		cmd_lst = cmd_lst->next;
	}
	return (0);
}

int	heredoc(t_cmd *cmd, t_file *file, t_env *lst)
{
	int		fd_temp;
	char	*buf[2];

	fd_temp = open(cmd->hd_file, O_RDWR | O_CREAT | O_TRUNC, 00644);
	if (fd_temp == -1)
		return (1);
	while (1)
	{
		write(0, "> ", 2);
		buf[0] = get_next_line(0);
		if (!buf[0])
			return (1);
		rm_newline(&buf[0]);
		if (ft_memcmp(file->delim, buf[0], ft_strlen(file->delim) + 1) == 0)
			break ;
		buf[1] = check_expand(buf[0], -1, lst, 0);
		if (!buf[1])
			return (1);
		free(buf[0]);
		ft_putstr_fd_mod(buf[1], fd_temp);
		free(buf[1]);
	}
	free(buf[0]);
	return (close(fd_temp), 0);
}
