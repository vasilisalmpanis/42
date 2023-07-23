/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:01:51 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/18 11:30:09 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * Function: no_parameters
 * --------------------
 * Prints the available options when the parameters passed are incorrect.
 */
void	no_parameters(void)
{
	ft_printf("Available sets:\n");
	ft_printf("---> Mandelbrot\n");
	ft_printf("---> Julia (-2<x<2) (-2<y<2)\n");
	ft_printf("---> Burning ships\n");
	exit(1);
}

void	check_input(char *argv)
{
	int	i;
	int	dotflag;
	int	pmflag;

	i = -1;
	dotflag = 0;
	pmflag = 0;
	if (ft_strlen(argv) == 0)
		no_parameters();
	while (argv[++i])
	{
		if (argv[i] == '.' | argv[i] == ',')
			dotflag++;
		else if (argv[i] == '+' | argv[i] == '-')
			pmflag++;
		if (!(ft_strchr("0123456789.,+-", argv[i])) \
			|| pmflag > 1 || dotflag > 1)
		{
			write(1, "Please specify the correct", 26);
			write(1, " parameters for the julia set\n", 31);
			exit(1);
		}
	}
}
