/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:34:55 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/21 12:36:00 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(t_data *object)
{
	int		len;
	int		bytes;
	char	buf[BUFFER_SIZE];

	if (pipe(object->here_d) == -1)
		cmd_failed("pipe");
	len = ft_strlen(object->argv[2]);
	write(1, "heredoc> ", 9);
	bytes = read(0, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		buf[bytes] = 0;
		if (bytes == len + 1 && ft_memcmp(object->argv[2], buf, len) == 0)
			break ;
		write(object->here_d[WRITE_END], buf, bytes);
		write(1, "heredoc> ", 9);
		bytes = read(0, buf, BUFFER_SIZE);
	}
	close(object->here_d[WRITE_END]);
}

void	make(int argc, char **argv, char **env, t_data *object)
{
	object->argc = argc;
	object->argv = argv;
	object->env = env;
	object->split = NULL;
	object->cmd = NULL;
}

void	check_arguments(int argc, char **argv, t_data *object, char **env)
{
	if (argc < 5)
	{
		ft_printf("file1 cmd1 cmd2 file2\n");
		exit(1);
	}
	make(argc, argv, env, object);
	if (strncmp(object->argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
	{
		if (argc < 6)
			object->here_doc = 0;
		else
			object->here_doc = 1;
	}
	else
		object->here_doc = 0;
	if (object->here_doc)
		make_elements(object, 4);
	else
		make_elements(object, 3);
}

void	make_elements(t_data *object, int i)
{
	int	j;

	j = -1;
	object->pid = malloc((object->argc - i) * sizeof(pid_t));
	while (++j < (object->argc - i))
		object->pid[j] = 0;
}
