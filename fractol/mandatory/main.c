/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:54:14 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/24 11:11:49 by valmpani         ###   ########.fr       */
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

/*
 * Function:  ft_end
 * --------------------
 * Destroys the window and images created in the init_fractol
 * Frees the set struct and the ui struct allocated in the
 * init_fractol.
 */
int	ft_end(t_var *ui)
{
	mlx_destroy_image(ui->f->mlx, ui->f->img);
	mlx_destroy_window(ui->f->mlx, ui->f->win);
	free(ui->f);
	free(ui);
	exit(1);
}

void	hooks(t_var *ui)
{
	mlx_mouse_hook(ui->f->win, &handle_mouse, ui);
	mlx_key_hook(ui->f->win, &keyboard_input, ui);
	mlx_hook(ui->f->win, 17, 0L, ft_end, ui);
	mlx_loop_hook(ui->f->mlx, &handle_no_events, ui);
	draw_window(ui);
	mlx_loop(ui->f->mlx);
	ft_end(ui);
}

/*
 * Function:  main
 * --------------------
 * Parses input, and prints error messages,
 * Initializes values for the GUI
 * Hooks the keyboard and mouse to the respective functions
 * Destroys the window and images created in the init_fractol
 * Returns 0 if the program is executed successfully.
 */

t_var	*mandel_bs(char **argv)
{
	t_var	*ui;

	if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) == 0 && \
		ft_strlen(argv[1]) == 10)
		ui = init_fractol("Mandelbrot", draw_mandelbrot);
	else if ((ft_strncmp(argv[1], "Burning ship", ft_strlen(argv[1])) == 0) \
		&& ft_strlen(argv[1]) == 12)
		ui = init_fractol("Burning ship", draw_bs);
	else
	{
		no_parameters();
		exit(1);
	}
	return (ui);
}

int	main(int argc, char **argv)
{
	t_var	*ui;

	if (argc == 1)
		no_parameters();
	if ((ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) \
			== 0 && ft_strlen(argv[1]) == 5) && argc == 4)
		ui = init_julia("Julia", draw_julia, argv, argc);
	else if (argc == 2)
		ui = mandel_bs(argv);
	else
	{
		no_parameters();
		exit(1);
	}
	hooks(ui);
	return (0);
}
