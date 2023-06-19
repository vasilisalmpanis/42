/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:46:50 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 14:03:34 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	object;

	if (argc != 5)
	{
		ft_printf("file1 cmd cmd file2\n");
		return (1);
	}
	object.argc = argc;
	object.argv = argv;
	object.env = env;
	object.file[0] = has_access(object);
	if (object.file[0] == -1)
		error_files(object.argv[1], object.argv[1]);
	object.file[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (object.file[1] == -1)
		error_files(object.argv[argc - 1], object.argv[argc - 1]);
	if (object.file[0] == -1)
		exit (1);
	return (0);
}
