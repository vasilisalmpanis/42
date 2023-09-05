/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:54:36 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/30 11:54:36 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_prog	*prog;
	int		*num;
	int		i;

	num = parse(argv, argc);
	if (!num)
		return (printf("Parsing error please give the correct parameters.\n"), 1);
	prog = initialize_prog(num, argc);
	if (!prog)
		return (1);
	i = -1;
	while (1)
	{
		if (check_if_full(prog))
			break ;
	}
	join_threads(prog);
	return (0);
}
