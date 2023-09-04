/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:13:07 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/24 17:17:35 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "minishell.h"

t_cmd	*ft_new_cmd(int id, char **env_paths, int exit_code);
void	ft_cmd_lstadd_end(t_cmd **lst, t_cmd *new);
t_file	*create_new_file(char *delim, t_token token, char *name);
void	ft_file_lst_add(t_file **lst, t_file *new_file);
void	add_start_lst(t_cmd *cmd);

void	free_cmd_lex_env(t_cmd **cmd_lst, t_lex **lex_lst, char **env_paths);
void	ft_cmd_lst_free(t_cmd **lst);
void	ft_free_file_lst(t_file **lst);
void	ft_lst_free(t_lex **lst);
void	free_mem_fd(int **fd, int num_cmds);
void	ft_cmd_lst_free_child(t_cmd *lst);
void	free_stuff(t_env **env_lst, t_cmd *cmd, char **env_array);
void	free_env_cmd_ex(t_env **lst, t_cmd *cmd);

t_lex	*ft_new_tk(void *value, t_token token, int pos);
void	ft_lstadd_end(t_lex **lst, t_lex *new);

char	**split_args(char *input);
char	*ft_charjoin_mod(char *s1, char s2);
char	*ft_strjoin_mod(char *s1, char *s2);
void	rm_newline(char **str);
void	ft_putstr_fd_mod(char *s, int fd);

char	*handle_redirects(char *input);
char	*add_space_pre_redir(char *input, int j);
char	*add_space_post_redir(char *input, int j);
int		calc_redir_wo_space(char *input);
int		calc_redir_wo_space2(char *input);

void	skip_quotes(char *input, int *i, char **new_input, int *j);
void	skip_quotes2(char *input, int *i);

int		env_lst_size(t_env *env_lst);
int		ft_check_lex(t_lex *lst);
int		check_token_err(char *word);
int		check_token_pipe_err(t_lex *lst, t_lex *lst_start);
char	*ft_getenv(t_env *lst, char *key);

int		allocate_args(t_lex *lex_lst, t_cmd *new_cmd);

#endif