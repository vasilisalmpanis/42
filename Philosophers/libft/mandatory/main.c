/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:26:28 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/24 17:13:30 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		g_signal_num;

void	start_env(t_env **exit_code, t_env *env_list, int argc)
{
	if (argc > 1)
		exit (1);
	while (env_list)
	{
		if (ft_strncmp("EC", env_list->key, ft_strlen(env_list->key)) == 0
			&& ft_strlen(env_list->key) == 2)
			*exit_code = env_list;
		env_list = env_list->next;
	}
	silence();
}

void	set_ex_code(t_env **exit_code)
{
	signals(handle_sigint);
	if (g_signal_num == 258)
	{
		(*exit_code)->ec = g_signal_num;
		g_signal_num = 0;
	}
	else if (g_signal_num > 0)
	{
		(*exit_code)->ec = 128 + g_signal_num;
		g_signal_num = 0;
	}
	else if (g_signal_num == -1)
	{
		(*exit_code)->ec = 1;
		g_signal_num = 0;
	}
}

char	*ft_get_prompt(t_env **env_lst)
{
	char	*temp;
	char	*result;

	temp = prompt();
	result = readline(temp);
	free(temp);
	if (!result)
	{
		printf("Hello\n");
		exit_builtin(env_lst, NULL);
	}
	add_history(result);
	return (result);
}

void	run_minishell(t_env **env_lst, t_env **exit_code, char *input)
{
	t_lex	*lex_lst;
	t_cmd	*cmd_lst;

	lex_lst = NULL;
	cmd_lst = NULL;
	lex_lst = lex(input, *env_lst);
	if (!lex_lst)
		(*exit_code)->ec = 1;
	else if (ft_check_lex(lex_lst))
		(*exit_code)->ec = 0;
	else if (check_token_pipe_err(lex_lst, lex_lst))
		(*exit_code)->ec = 258;
	else
	{
		cmd_lst = parser(lex_lst, *env_lst, (*exit_code)->ec);
		if (!cmd_lst)
			(*exit_code)->ec = 1;
		else
		{
			add_start_lst(cmd_lst);
			(*exit_code)->ec = execute(cmd_lst, env_lst, exit_code);
		}
	}
	ft_cmd_lst_free(&cmd_lst);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_env	*exit_code;
	t_env	*env_lst;

	env_lst = create_env(envp, argv);
	start_env(&exit_code, env_lst, argc);
	if (!env_lst)
		return (1);
	while (1)
	{
		set_ex_code(&exit_code);
		input = ft_get_prompt(&env_lst);
		if (input[0] == '\0')
			exit_code->ec = 0;
		else
			run_minishell(&env_lst, &exit_code, input);
	}
	return (0);
}
