/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:59:27 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/23 15:39:09 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# define IN 0
# define OUT 1

# include "minishell.h"

int		execute(t_cmd *cmd_lst, t_env **env_lst, t_env **ec);
pid_t	execute_cmd(t_cmd *cmd_lst, t_env **env_lst, int **fd, int count_cmds);
int		builtin_child(t_cmd *cmd, t_env **env_lst, int **fd, int count);
int		builtin_process(t_cmd *cmd, t_env **env_lst, int **fd);
int		child_process(t_cmd *cmd_lst, t_env **env_lst, int **fd, int count);

int		count_cmds(t_cmd *cmd_lst);
int		**allocate_fds(int count);
int		create_pipes(int **fd, int count);
void	close_fds(int **fd, int count);
int		**ft_fds_pipes(int num_cmds);

int		wait_for_children(t_cmd *start);
int		exec_builtin(t_cmd *cmd, t_env **env_lst);
char	**new_env(t_env *env_lst);
int		check_path_existence(t_env *env_lst);
void	ft_print_error_msg(char *msg, int exit_code, int flag);
void	ft_check_errors(t_env **env_lst, t_cmd *cmd, char **env_array);

int		open_files(t_cmd *cmd, int **fd);
int		*open_in_out_files(t_file *file_lst);
int		open_in_out_files_helper(t_file *file_lst, int	*fd_temp);

int		open_in_file(t_file *file);
int		open_out_file(t_file *file);

int		heredoc(t_cmd *cmd, t_file *file, t_env *lst);
int		open_heredocs(t_cmd *cmd_lst, t_env *lst, int i);

int		set_stdin(int flag, int *fd_in_out, t_cmd *cmd, int **fd);
int		set_stdout(int *fd_in_out, int **fd, t_cmd *cmd);

#endif