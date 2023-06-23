/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:46:50 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 17:50:19 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	t_data	object;

	check_arguments(argc, argv, &object, env);
	object.argv = argv;
	if (object.here_doc)
		here_doc(&object);
	if (object.here_doc)
		object.file[READ_END] = object.here_d[READ_END];
	else
	{
		object.file[0] = has_access(object);
		if (object.file[0] == -1)
			error_files(object.argv[1], object.argv[argc - 1]);
	}
	object.file[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (object.file[1] == -1)
		error_files(object.argv[argc - 1], object.argv[argc - 1]);
	if (object.file[0] == -1 && object.file[1] == -1)
		exit (1);
	execute_commands(object);
	return (0);
}

