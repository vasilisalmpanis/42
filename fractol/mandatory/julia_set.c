/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:06:20 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/18 11:29:04 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_calc_start(t_complex *f)
{
	f->z_r = ((f->x / f->width) * (f->max_r - f->min_r)) - \
		(f->max_r - f->min_r) / 2 + f->r_origin;
	f->z_i = ((f->y / f->height) * (f->max_i - f->min_i)) \
		- (f->max_i - f->min_i) / 2 + f->i_origin;
	f->iter = 0;
}

void	julia_calc_z(t_complex *f)
{
	while ((pow(f->z_r, 2) + pow(f->z_i, 2)) <= 4 && f->iter < f->max_it)
	{
		f->temp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = (2 * f->z_i * f->z_r) - f->c_i;
		f->z_r = f->temp;
		f->iter++;
	}
}

void	julia_change_c(int x, int y, t_var *ui)
{
	ui->f->x = (double)x;
	ui->f->y = (double)y;
	ui->f->c_r = ((ui->f->x / ui->f->width) * (ui->f->max_r - ui->f->min_r)) - \
		(ui->f->max_r - ui->f->min_r) / 2 + ui->f->r_origin;
	ui->f->c_i = ((ui->f->y / ui->f->height) * (ui->f->max_i - ui->f->min_i)) \
		- (ui->f->max_i - ui->f->min_i) / 2 + ui->f->i_origin;
	mlx_clear_window(ui->f->mlx, ui->f->win);
	draw_window(ui);
}

void	draw_julia(t_complex *f)
{
	f->y = -1;
	f->temp = 0;
	while (++(f->y) < f->height)
	{
		f->x = -1;
		while (++(f->x) < f->width)
		{
			julia_calc_start(f);
			julia_calc_z(f);
			my_put_pixel(f, f->calc_color(f->iter));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
