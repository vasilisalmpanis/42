/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:59:30 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/14 15:33:48 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractol(t_complex *f, char *title)
{
	f->width = WIDTH;
	f->height = WIDTH / 2;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->width, f->height, title);
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	f->img_data = mlx_get_data_addr(f->img, &f->bpp, &f->size_line, &f->endian);
	f->max_r = 2.5;
	f->min_r = -2.5;
	f->max_i = 1.25;
	f->min_i = -1.25;
	f->r_origin = 0.0;
	f->i_origin = 0.0;
	f->calc_color = calc_color;
}
