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
	ft_printf("---> Julia\n");
	ft_printf("---> Burning ships\n");
	exit(1);
}
