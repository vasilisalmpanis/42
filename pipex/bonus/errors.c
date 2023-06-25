/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:58:45 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 14:07:39 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_files(char *object, char *argv)
{
	write(STDERR_FILENO, "pipex: ", 7);
	perror(object);
	if (ft_strncmp(object, argv, ft_strlen(object)) == 0)
		exit(0);
}

void	cmd_not_found(char *cmd)
{
	write(STDERR_FILENO, "pipex: ", 7);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(2);
}

void	cmd_failed(char *str)
{
	perror(str);
	exit(1);
}
