/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:51:08 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/17 16:52:22 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	bs_calc_c(t_complex *f)
{
	f->c_r = ((f->x / f->width) * (f->max_r - f->min_r)) \
	- (f->max_r - f->min_r) / 2 + f->r_origin;
	f->c_i = ((f->y / f->height) * (f->max_i - f->min_i)) \
	- (f->max_i - f->min_i) / 2 + f->i_origin;
	f->z_r = 0.0;
	f->z_i = 0.0;
	f->iter = 0;
}

void	bs_calc_z(t_complex *f)
{
	while ((pow(f->z_r, 2) + pow(f->z_i, 2)) < 4 && f->iter < f->max_it)
	{
		f->temp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		if (2 * f->z_r * f->z_i < 0)
			f->z_i = (2 * f->z_r * f->z_i) - f->c_i;
		else
			f->z_i = (-2 * f->z_r * f->z_i) - f->c_i;
		f->z_r = f->temp;
		f->iter++;
	}
}