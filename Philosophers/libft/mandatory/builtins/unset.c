/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 09:02:53 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/24 14:36:49 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	unset(t_env **lst, t_cmd *cmd)
{
	int	i;
	int	err_code;

	i = -1;
	err_code = 0;
	while (cmd->args[++i])
	{
		if (check_arg(cmd->args[i], "unset"))
			err_code = 1;
		else if (ft_strncmp("EC", cmd->args[i], ft_strlen(cmd->args[i])) == 0
			&& ft_strlen(cmd->args[i]) == 2)
			err_code = 0;
		else
			ft_env_remove(lst, cmd->args[i]);
	}
	return (err_code);
}
