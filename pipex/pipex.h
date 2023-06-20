/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:47:12 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 17:22:18 by valmpani         ###   ########.fr       */
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
	int		file[2];
	pid_t	pid[2];
	char	**split;
	char	*cmd;
	int		argc;
	char	**argv;
	char	**env;
}	t_data;

int		main(int argc, char **argv, char **env);
void	error_files(char *object, char *argv);
void	cmd_not_found(char *cmd);
void	cmd_failed(char *str);
void	execute_commands(t_data object);
void	child_process(t_data object, int i);
void	parent_process(t_data object);
char	*find_command(t_data object, int i);
char	*command_access(char *env, char *cmd);
char	**split_args(t_data object, int i);
int		has_access(t_data object);
char	*environment(t_data object);

#endif