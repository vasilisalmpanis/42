/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:47:12 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 11:23:24 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_data
{
	int		fd[2];
	int		file_fd[2];
	pid_t	pid[2];
	char	**split;
	char	*cmd;
	int		argc;
	char	**argv;
	char	**env;
}	t_data;

int	main(int argc, char **argv, char **env);

#endif