/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:58:33 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/15 15:24:36 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_put_pixel(t_complex *f, int color)
{
	char	*dst;

	dst = f->img_data + ((int)f->y * f->size_line + (int)f->x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_lines(t_complex *f)
{
	mlx_string_put(f->mlx, f->win, f->width - 150, 25, "0xFFFFFF", "Iterations:");
	mlx_string_put(f->mlx, f->win, f->width - 70, 25, "0xFFFFFF", ft_itoa(f->max_it));
}

void	draw_window(t_complex *f)
{
	draw_set(f);
	print_lines(f);
}

void	draw_set(t_complex *f)
{
	double	p;

	f->y = -1;
	f->temp = 0;
	while (++(f->y) < f->height)
	{
		f->x = -1;
		while (++(f->x) < f->width)
		{
			mandlel_calc_c(f);
			p = pow((f->x + 1), 2) + pow(f->y, 2);
			if (p <= 1 / 16)
				my_put_pixel(f, f->calc_color(0));
			else
			{
				while ((pow(f->z_r, 2) + pow(f->z_i, 2)) < 4 && f->iter < f->max_it)
					mandel_calc_z(f);
				my_put_pixel(f, f->calc_color(f->iter));
			}
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
