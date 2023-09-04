/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:20:07 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/24 15:47:19 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_env	t_env;

typedef struct s_file
{
	char			*name;
	t_token			token;
	char			*delim;
	struct s_file	*next;
}				t_file;

typedef struct s_cmd
{
	char			*cmd;
	char			*path;
	char			**args;
	int				builtin;
	int				path_known;
	int				is_sh_script;
	pid_t			pid;
	int				cmd_id;
	int				env_flag;
	int				exit_code;
	char			*hd_file;
	int				hd_last;
	t_file			*file;
	struct s_cmd	*start;
	struct s_cmd	*next;
}				t_cmd;

t_cmd	*parser(t_lex *lex_lst, t_env *env_lst, int ex_co);
char	**extract_paths(t_env *env_lst);
int		parse_tokens(t_lex *lex_lst, t_cmd **cmd_lst, \
						char **env_paths, int exit_code);
int		analyze_token(t_lex **lex_lst, t_cmd *new_cmd, \
						int *arg_num, char **env_p);
int		init_args(t_lex *lex_lst, t_cmd *new_cmd, int *arg_num);

int		check_for_builtin(t_lex **lex_lst, t_cmd *new_cmd);
void	check_for_path(t_lex **lex_lst, t_cmd *new_cmd);
int		get_cmd_name(t_lex **lex_lst, t_cmd *new_cmd);
int		get_path_name(t_cmd *new_cmd, char **env_paths);

int		set_here_doc_flag(t_lex **lex_lst, t_cmd *new_cmd);
int		set_redir_flags(t_lex **lex_lst, t_cmd *new_cmd);

int		analyze_word(t_lex **lex_lst, t_cmd *new_cmd, \
						int *arg_num, char **env_p);
int		check_word_type(t_cmd *cmd, t_lex *lex_lst);
int		analyze_cmd(t_lex **lex_lst, t_cmd *new_cmd, \
						int *arg_num, char **env_p);
int		analyze_opt(t_lex **lex_lst, t_cmd *new_cmd);

#endif