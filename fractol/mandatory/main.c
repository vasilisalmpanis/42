/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:54:14 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/18 12:03:12 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_end(t_var *ui)
{
	mlx_destroy_image(ui->f->mlx, ui->f->img);
	mlx_destroy_window(ui->f->mlx, ui->f->win);
	free(ui->f);
	free(ui);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_var	*ui;

	if (argc != 2)
		no_parameters();
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		ui = init_fractol("Mandelbrot", draw_mandelbrot);
	else if (ft_strncmp(argv[1], "Burning ship", 12) == 0)
		ui = init_fractol("Burning ship", draw_bs);
	else
		ui = init_fractol("Julia", draw_julia);
	mlx_mouse_hook(ui->f->win, &handle_mouse, ui);
	mlx_key_hook(ui->f->win, &keyboard_input, ui);
	mlx_hook(ui->f->win, 17, 0L, ft_end, ui);
	mlx_loop_hook(ui->f->mlx, &handle_no_events, ui);
	draw_window(ui);
	mlx_loop(ui->f->mlx);
	ft_end(ui);
	return (0);
}
