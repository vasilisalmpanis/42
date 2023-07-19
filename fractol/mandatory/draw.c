/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:58:33 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/17 17:21:58 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * Function:  my_put_pixel
 * --------------------
 * @colour :  colour to be put
 * @f : Pointer to the f struct
 * Shifts the shift_rate
 */
void	my_put_pixel(t_complex *f, int color)
{
	char	*dst;

	dst = f->img_data + ((int)f->y * f->size_line + (int)f->x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

/*
 * Function: print_lines
 * --------------------
 * @f : Pointer to the f struct
 * Prints the overlay of iterations.
 */
void	print_lines(t_complex *f)
{
	int		i;
	char	*str;
	char	*itoa;
	int		space;

	i = 255;
	str = "Iterations:";
	space = f->width - 150;
	itoa = ft_itoa(f->max_it);
	mlx_string_put(f->mlx, f->win, space, 25, i, str);
	mlx_string_put(f->mlx, f->win, f->width - 40, 25, i, itoa);
	free(itoa);
}

/*
 * Function: draw_window
 * --------------------
 * @ui : Pointer to the ui struct
 * Draws the set and prints the overlay.
 */
void	draw_window(t_var *ui)
{
	ui->set(ui->f);
	print_lines(ui->f);
}

/*
 * Function:  draw_Mandelbrot
 * --------------------
 * @f : Pointer to the f struct
 * Calculates the colour for every pixel in the image and puts it.
 */
void	draw_mandelbrot(t_complex *f)
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
				mandel_calc_z(f);
				my_put_pixel(f, f->calc_color(f->iter));
			}
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

/*
 * Function:  draw_bs
 * --------------------
 * @f : Pointer to the f struct
 * Calculates the colour for every pixel in the image and puts it.
 */
void	draw_bs(t_complex *f)
{
	double	p;

	f->y = -1;
	f->temp = 0;
	while (++(f->y) < f->height)
	{
		f->x = -1;
		while (++(f->x) < f->width)
		{
			bs_calc_c(f);
			p = pow((f->x + 1), 2) + pow(f->y, 2);
			bs_calc_z(f);
			my_put_pixel(f, f->calc_color(f->iter));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
