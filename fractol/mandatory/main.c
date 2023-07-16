/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:52:03 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/16 12:45:16 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_end(t_complex *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_complex	f;

	if (argc != 2)
		no_parameters();
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		init_fractol(&f, "Mandelbrot");
		mlx_mouse_hook(f.win, &handle_mouse, &f);
		mlx_key_hook(f.win, &keyboard_input, &f);
		mlx_hook(f.win, 17, 0L, ft_end, &f);
		draw_window(&f);
		mlx_loop(f.mlx);
		mlx_destroy_image(f.mlx, f.img);
		mlx_destroy_window(f.mlx, f.win);
	}
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		ft_printf("Julia\n");
	return (0);
}
