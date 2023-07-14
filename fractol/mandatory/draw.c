/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:58:33 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/14 15:17:22 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_put_pixel(t_complex *f, int color)
{
	char	*dst;

	dst = f->img_data + ((int)f->y * f->size_line + (int)f->x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_set(t_complex *f)
{
	f->y = -1;
	f->temp = 0;
	while (++(f->y) < f->height)
	{
		f->x = -1;
		while (++(f->x) < f->width)
		{
			mandlel_calc_c(f);
			while ((f->z_r * f->z_r + f->z_i * f->z_i) < 4 && f->iter < M_I)
				mandel_calc_z(f);
			my_put_pixel(f, f->calc_color(f->iter));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
