/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:01:51 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/12 20:27:41 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	no_parameters(void)
{
	ft_printf("Available sets:\n");
	ft_printf("---> Mandelbrot\n");
	ft_printf("---> Julia\n");
	exit(0);
}
