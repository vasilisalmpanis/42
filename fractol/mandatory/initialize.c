/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:59:30 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/18 11:17:40 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_var	*init_fractol(char *title, void *set)
{
	t_var	*ui;

	ui = (t_var *)malloc(sizeof(t_var));
	ui->f = (t_complex *)malloc(sizeof(t_complex));
	ui->f->width = WIDTH;
	ui->f->height = WIDTH / 2;
	ui->f->mlx = mlx_init();
	ui->f->win = mlx_new_window(ui->f->mlx, ui->f->width, ui->f->height, title);
	ui->f->img = mlx_new_image(ui->f->mlx, ui->f->width, ui->f->height);
	ui->f->img_data = \
	mlx_get_data_addr(ui->f->img, \
	&ui->f->bpp, &ui->f->size_line, &ui->f->endian);
	ui->f->max_r = 2.5;
	ui->f->min_r = -2.5;
	ui->f->max_i = 1.25;
	ui->f->min_i = -1.25;
	ui->f->r_origin = 0.0;
	ui->f->i_origin = 0.0;
	ui->f->max_it = M_I;
	ui->f->calc_color = polynomial;
	ui->set = set;
	ui->f->shift_rate = SHIFT_RATE;
	ui->f->shift = 0;
	return (ui);
}
