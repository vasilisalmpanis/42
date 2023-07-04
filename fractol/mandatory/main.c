/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:33:55 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/04 15:30:57 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Fract-ol");
	for (int i = 0; i < 500; i++)
	{
		for (int x = 0; x < 500; x++)
		{
			if (x % 2 != 0)
				mlx_pixel_put(mlx, mlx_win, i, x, 0x000000);
			else if (x % 3 == 0)
				mlx_pixel_put(mlx, mlx_win, i, x, 0x00FF00);
			else
				mlx_pixel_put(mlx, mlx_win, i, x, 0xFF0000);
		}
	}
	// mlx_string_put(mlx, mlx_win, 250, 250, 0xFFFFFF, "hello world\n");
	// mlx_string_put(mlx, mlx_win, 250, 260, 0xFFFFFF, "hello world\n");
	mlx_loop(mlx);
}
