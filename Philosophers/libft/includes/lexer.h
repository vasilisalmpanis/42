/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:31:53 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/23 15:39:26 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_env	t_env;

typedef enum s_token
{
	TK_WORD = 'w',
	TK_PIPE = '|',
	TK_IN_R = '<',
	TK_OUT_R = '>',
	TK_APP_R = 'A',
	TK_HERE_DOC = 'H',
}			t_token;

typedef struct s_lex
{
	t_token			token;
	char			*value;
	int				pos;
	struct s_lex	*next;
}				t_lex;

int		check_quotes(const char *input, int single, int dbl);
t_lex	*lex(char *input, t_env *lst);
t_lex	*create_token(char *split, int *pos, t_env *lst);
int		create_word_token(char *split, int *pos, t_lex **new_token,
			t_env *lst);
int		check_syntax_err(char *split);

char	*check_expand(char *split, int i, t_env *lst, int trim_flag);
int		check_expand_helper(char *split, int *i, char **exp_word,
			t_env *lst);
int		expand(char *split, int *i, char **exp_word, t_env *lst);

char	*trim_word(char *exp_word);
int		calc_offset(char *split, int start, int *i);
char	*remove_quotes(char *split, int i, int j);
int		count_rm_quotes(char *split);

int		create_exp_var(char *split, int *i, t_env *lst, char **exp_var);
int		determine_exp_var(char *temp, t_env *lst, char **exp_var);
int		find_exp_var(char *temp, char **exp_var, t_env *lst);
char	*find_exit_code(char *temp, t_env *lst);
char	*find_pid(int *i);

#endif
