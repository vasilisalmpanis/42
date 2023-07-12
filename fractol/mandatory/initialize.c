/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:59:30 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/12 20:02:23 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractol(t_complex *f, char *title)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, title);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img_data = mlx_get_data_addr(f->img, &f->bpp, &f->size_line, &f->endian);
	f->max_r = 2.0;
	f->min_r = -2.0;
	f->max_i = 1.0;
	f->min_i = -1.0;
	f->calc_color = calc_color;
}
