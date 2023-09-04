/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:59:44 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/23 15:43:27 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * Function:  export
 * --------------------
 * Prints the env list if cmd has no arguments
 * Checks for syntactic errors in the key to be added
 * Adds the key to the end of the list and thr value accordingly if it exists
 * @lst	Reference to the env list
 * @cmd Reference to the command given by lexer
 */
int	export(t_env **lst, t_cmd *cmd)
{
	if (!cmd->args[0])
	{
		export_print(*lst);
		return (0);
	}
	return (export_args(lst, cmd));
}

/*
 * Function:  check_arg
 * --------------------
 * Checks the list arguments passed to export for syntactical errors and sets
 * the error code to be returned
 * @arg the argument list
 */
int	check_arg(char *arg, char *name)
{
	int		i;
	int		letter_flag;
	char	*temp;

	i = -1;
	(void)name;
	letter_flag = 0;
	temp = ft_strtrim(arg, "'");
	if (!temp)
		return (1);
	if (temp[0] == '=')
	{
		free(temp);
		return (ft_putstr_fd(" not a valid identifier\n", 2), 1);
	}
	while (temp[++i] && temp[i] != '=')
	{
		if ((letter_flag == 0) && (ft_isalpha(temp[i]) == 1))
			letter_flag = 1;
		if (letter_flag == 0 && ft_isdigit(temp[i]) == 1)
			return (ft_putstr_fd(" not a valid identifier\n", 2), 1);
		if (ft_strchr("!@#$%^&*()+-", temp[i]) || ft_isspace(temp[i]) == 1)
			return (ft_putstr_fd(" not a valid identifier\n", 2), 1);
	}
	return (free(temp), 0);
}

/*
 * Function:  ft_split_key_val
 * --------------------
 * Prints the env list if cmd has no arguments
 * Checks for syntactic errors in the key to be added
 * Adds the key to the end of the list and thr value accordingly if it exists
 * @lst	The individual argument to be processed
 * @key Reference to the key to be passed for the new node
 * @value Reference to the value to be passed for the new node
 */
void	ft_split_key_val(char *arg, char **key, char **value)
{
	char	*temp;
	char	*sign;

	if (arg[0] == '=')
		sign = ft_strchr(arg + 1, '=');
	else
		sign = ft_strchr(arg, '=');
	if (!sign)
	{
		*key = ft_substr(arg, 0, ft_strlen(arg));
		*value = ft_strdup("");
	}
	else
	{
		*key = ft_substr(arg, 0, sign - arg);
		*value = ft_substr(sign + 1, 0, ft_strlen(arg) - (sign - arg));
	}
	temp = ft_strtrim(*key, "\"\'");
	free(*key);
	*key = temp;
	if ((*value)[0] != '\0')
		temp = ft_strtrim(*value, "\"\'");
	else
		temp = ft_strdup("");
	free(*value);
	*value = temp;
}

/*
 * Function:  export_args
 * --------------------
 * Exports the arguments passed to export. If there is problem
 * with the variable names it sets the error code to 1 otherwise
 * it returns 0.
 * @lst	Reference to the env list
 * @cmd Reference to the command given by lexer
 */
int	export_args(t_env **lst, t_cmd *cmd)
{
	int		er_code;
	int		i;
	char	*key;
	char	*value;
	t_env	*new_node;

	er_code = 0;
	i = -1;
	while (cmd->args[++i])
	{
		ft_split_key_val(cmd->args[i], &key, &value);
		if (!key || !value)
			++i;
		else if (check_arg(key, "export") == 1)
			er_code = 1;
		else
		{
			new_node = lst_env_node(key, value);
			ft_env_addback(lst, new_node);
		}
		free(key);
		free(value);
	}
	return (er_code);
}
