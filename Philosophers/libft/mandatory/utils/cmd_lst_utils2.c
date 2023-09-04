/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:46:14 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/24 16:35:30 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	allocate_args(t_lex *lex_lst, t_cmd *new_cmd)
{
	int		arg_num;
	t_lex	**start_lst;

	start_lst = &lex_lst;
	arg_num = 0;
	while (*start_lst && (*start_lst)->token != TK_PIPE)
	{
		if ((*start_lst)->token == TK_WORD && (*start_lst)->value[0])
			arg_num++;
		else if (((*start_lst)->token == TK_IN_R
				|| (*start_lst)->token == TK_OUT_R
				|| (*start_lst)->token == TK_APP_R
				|| (*start_lst)->token == TK_HERE_DOC) 
			&& (*start_lst)->next && (*start_lst)->next->token == TK_WORD)
			arg_num -= 1;
		start_lst = &(*start_lst)->next;
	}
	if (arg_num >= 0)
	{
		new_cmd->args = ft_calloc((arg_num + 1), sizeof(char *));
		if (!new_cmd->args)
			return (1);
	}
	return (0);
}
