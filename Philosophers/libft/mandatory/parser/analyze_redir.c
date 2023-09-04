/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:46:21 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/24 16:28:32 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_signal_num;

int	set_here_doc_flag(t_lex **lex_lst, t_cmd *new_cmd)
{
	t_file	*new_file;

	if (!(*lex_lst)->next)
	{
		ft_putstr_fd("Error: No delimiter provided for heredoc\n", 2);
		return (g_signal_num = 258, 1);
	}
	*lex_lst = (*lex_lst)->next;
	if ((*lex_lst)->token != TK_WORD)
	{
		ft_putstr_fd("Error: No delimiter provided for heredoc\n", 2);
		return (g_signal_num = 258, 1);
	}
	new_file = create_new_file((*lex_lst)->value, TK_HERE_DOC, NULL);
	if (!new_file)
		return (1);
	ft_file_lst_add(&new_cmd->file, new_file);
	return (0);
}

int	set_redir_flags(t_lex **lex_lst, t_cmd *new_cmd)
{
	t_token	token;
	t_file	*new_file;

	token = (*lex_lst)->token;
	if (!(*lex_lst)->next)
	{
		printf("Minishell: syntax error near unexpected token '%c'\n",
			(*lex_lst)->token);
		return (g_signal_num = 258, 1);
	}
	*lex_lst = (*lex_lst)->next;
	if (!(*lex_lst) || (*lex_lst)->token != TK_WORD)
	{
		printf("Minishell: syntax error near unexpected token '%c'\n",
			(*lex_lst)->token);
		return (g_signal_num = 258, 1);
	}
	new_file = create_new_file(NULL, token, (*lex_lst)->value);
	if (!new_file)
		return (1);
	ft_file_lst_add(&new_cmd->file, new_file);
	return (0);
}
