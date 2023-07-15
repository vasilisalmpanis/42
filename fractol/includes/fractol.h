/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:33:25 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/15 12:40:21 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include "key_macros.h"

# define WIDTH 1200
# define M_I 20

typedef struct s_complex
{
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		r_origin;
	double		i_origin;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	double		x;
	double		y;
	double		temp;
	int			width;
	int			height;
	int			iter;
	int			bpp;
	int			size_line;
	int			endian;
	int			colours[M_I + 1];
	int			color;
	int			(*calc_color)(int iter);
}	t_complex;

// void	init_fractol(t_complex *f, char *title);
// void	draw_mandelbrot_set(t_complex f);
// int		handle_mouse(int button, int x, int y, t_complex *f);
// void	set_color(t_color *color, int red, int green, int blue);

void	draw_set(t_complex *f);
void	init_fractol(t_complex *f, char *title);
void	mandlel_calc_c(t_complex *f);
void	mandel_calc_z(t_complex *f);
void	my_put_pixel(t_complex *f, int color);
void	no_parameters(void);
int		handle_mouse(int button, int x, int y, t_complex *f);
int		calc_color(int iter);
int		polynomial(int iter);
int		basic(int iter);
int		set_color(int t, int r, int g, int b);

#endif