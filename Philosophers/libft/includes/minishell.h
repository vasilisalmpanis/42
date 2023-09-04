/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:26:53 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/23 11:49:09 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <string.h>
# include <signal.h>
# include <errno.h>
# include "lexer.h"
# include "builtins.h"
# include "parser.h"
# include "utils.h"
# include "execution.h"
# include "errors.h"
# include "../libft/libft.h"
# include "../includes/colors.h"
# define READLINE_LIBRARY
# include "../readline/include/history.h"
# include "../readline/include/readline.h"
# include "../readline/include/rlstdc.h"
# define HEREDOC "temp"

//SIGNALS
void	handle_sigquit(void);
void	handle_sigint(int signum);
void	handle_sigint_child(int signum);
void	handle_sigquit_child(int signum);
void	silence(void);
void	signals(void (*handler)(int));

//PROMPT
void	get_repo(char **input, char *head, char *w);
char	*get_git_head(char *w);
char	*prompt(void);
char	*current_dir(void);
char	*git_traversal(void);

//UTILS

// TESTING
void	ft_show_tab2(t_cmd *list);

//BUILTINS

#endif
