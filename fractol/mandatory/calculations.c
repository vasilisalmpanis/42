/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:00:26 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/16 13:36:29 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * Function:  mandlel_calc_c
 * --------------------
 * @f : pointer to the f struct
 * Calculates the c_r and c_i values for the Mandelbrot set.
 * Clears the window and redraws the set.
 */
void	mandlel_calc_c(t_complex *f)
{
	f->c_r = ((f->x / f->width) * (f->max_r - f->min_r)) \
	- (f->max_r - f->min_r) / 2 + f->r_origin;
	f->c_i = ((f->y / f->height) * (f->max_i - f->min_i)) \
	- (f->max_i - f->min_i) / 2 + f->i_origin;
	f->z_r = 0.0;
	f->z_i = 0.0;
	f->iter = 0;
}

/*
 * Function:  mandlel_calc_z
 * --------------------
 * @f : pointer to the f struct
 * Calculates the z_r and z_i values for the Mandelbrot set.
 * Clears the window and redraws the set.
 */
void	mandel_calc_z(t_complex *f)
{
	while ((pow(f->z_r, 2) + pow(f->z_i, 2)) < 4 && f->iter < f->max_it)
	{
		f->temp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = (2 * f->z_i * f->z_r) - f->c_i;
		f->z_r = f->temp;
		f->iter++;
	}
}
