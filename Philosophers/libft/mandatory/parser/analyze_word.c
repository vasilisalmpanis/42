/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:08:23 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/22 17:19:14 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	analyze_word(t_lex **lex_lst, t_cmd *new_cmd, int *arg_num, char **env_p)
{
	int		is_cmd;

	is_cmd = check_word_type(new_cmd, *lex_lst);
	if (is_cmd)
	{
		if (analyze_cmd(lex_lst, new_cmd, arg_num, env_p))
			return (1);
	}
	else
	{
		if ((*lex_lst)->value[0])
		{
			new_cmd->args[(*arg_num)] = ft_strdup((*lex_lst)->value);
			if (!((new_cmd->args)[(*arg_num)++]))
				return (1);
		}
	}
	return (0);
}

int	check_word_type(t_cmd *cmd, t_lex *lex_lst)
{
	if (cmd->cmd || lex_lst->value[0] == '\0')
		return (0);
	else
		return (1);
}

int	analyze_cmd(t_lex **lex_lst, t_cmd *new_cmd, int *arg_num, char **env_p)
{
	if (check_for_builtin(lex_lst, new_cmd))
		return (1);
	if (!new_cmd->builtin)
	{
		check_for_path(lex_lst, new_cmd);
		if (get_cmd_name(lex_lst, new_cmd))
			return (1);
		if (new_cmd->path_known)
		{
			new_cmd->path = ft_strdup((*lex_lst)->value);
			if (!new_cmd->path)
				return (1);
		}
		else
		{
			if (get_path_name(new_cmd, env_p))
				return (1);
		}
		(new_cmd->args)[(*arg_num)] = ft_strdup(new_cmd->cmd);
		if (!(new_cmd->args[(*arg_num)++]))
			return (1);
	}
	return (0);
}
