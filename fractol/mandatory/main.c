/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:52:03 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/12 19:54:48 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_complex	f;

	if (argc != 2)
		no_parameters();
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		init_fractol(&f, "Mandelbrot");
		mlx_mouse_hook(f.win, &handle_mouse, &f);
		draw_set(&f);
		mlx_loop(f.mlx);
	}
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		ft_printf("Julia\n");
	return (0);
}
