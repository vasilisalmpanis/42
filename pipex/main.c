/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:46:50 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 11:25:16 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	object;

	if (argc != 5)
	{
		ft_printf("file1 cmd cmd file2\n");
		return (-1);
	}
	object.argc = argc;
	object.argc = argv;
	object.env = env;
	if ()
}
