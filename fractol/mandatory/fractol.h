/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:33:25 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/07 12:39:58 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define WIDTH 1600
# define HEIGHT 900
# define M_I 250

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_complex
{
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		factor_r;
	double		factor_i;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	t_color		colours[M_I + 1];
	t_color		color;
}	t_complex;

t_complex	init_fractol(void);
void		draw_mandelbrot_set(t_complex f);
int			main(int argc, char **argv);

#endif