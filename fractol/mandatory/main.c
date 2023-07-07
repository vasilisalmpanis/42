/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:33:55 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/07 13:17:52 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	no_parameters(void)
{
	ft_printf("Available sets:\n");
	ft_printf("---> Mandelbrot\n");
	ft_printf("---> Julia\n");
	exit(0);
}

void	set_color(t_color *color, int red, int green, int blue)
{
	color->red = red;
	color->green = green;
	color->blue = blue;
}

void	draw_mandelbrot_set(t_complex f)
{
	double		temp;
	int			i;
	int			j;
	int			iteration;

	j = -1;
	while (++j < HEIGHT)
	{
		f.c_i = f.max_i - j * f.factor_i;
		i = -1;
		while (++i < WIDTH)
		{
			f.c_r = f.min_r + i * f.factor_r;
			f.z_r = 0;
			f.z_i = 0;
			iteration = 0;
			while (f.z_r * f.z_r + f.z_i * f.z_i <= 4 && iteration < M_I)
			{
				temp = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
				f.z_i = 2 * f.z_r * f.z_i + f.c_i;
				f.z_r = temp;
				iteration++;
			}
			if (iteration < M_I)
				f.color = f.colours[iteration];
			else
				set_color(&f.color, 0, 0, 0);

			f.img_data[(j * f.size_line) + (i * 4)] = f.color.blue;
			f.img_data[(j * f.size_line) + (i * 4) + 1] = f.color.green;
			f.img_data[(j * f.size_line) + (i * 4) + 2] = f.color.red;
		}
	}
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
}

t_complex	init_fractol(void)
{
	t_complex	c;
	int			i;
	int			red;
	int			green;
	int			blue;

	c.mlx = mlx_init();
	c.win = mlx_new_window(c.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	c.min_r = -2.0;
	c.min_i = -1.0;
	c.max_r = 1.0;
	c.max_i = 1.0;
	c.img = mlx_new_image(c.mlx, WIDTH, HEIGHT);
	c.img_data = mlx_get_data_addr(c.img, &c.bpp, &c.size_line, &c.endian);
	c.factor_r = (c.max_r - c.min_r) / (WIDTH - 1);
	c.factor_i = (c.max_i - c.min_i) / (HEIGHT - 1);
	i = -1;
	while (++i < M_I)
	{
		red = i % 256;
		green = (i * 2) % 256;
		blue = (i * 3) % 256;
		set_color(&c.colours[i], red, green, blue);
	}
	return (c);
}

int	main(int argc, char **argv)
{
	t_complex	f;

	if (argc != 2)
		no_parameters();
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		f = init_fractol();
		draw_mandelbrot_set(f);
		mlx_loop(f.mlx);
		return (0);
	}
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		ft_printf("Julia\n");
	return (0);
}
