/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:03:23 by hichokri          #+#    #+#             */
/*   Updated: 2024/05/16 20:54:14 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define VALUE 600

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct s_rgb
{
	int			red;
	int			green;
	int			blue;
}				t_rgb;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	int			max_iter;
	double		x;
	double		y;
	double		t;
	double		x_min;
	double		y_min;
	double		x_max;
	double		y_max;
	double		real;
	double		imaginary;
	double		cheft;
	char		name[100];
	int			iter;
	int			color;
	char		c;
	int			argc;
	char		**argv;
	char		*arv1;
	char		*arv2;
	t_image		image;
	t_rgb		rgb;
}				t_fractal;

typedef struct s_atof
{
	double		res;
	double		dec_part;
	int			divisor;
	int			sign;
	int			decimal_places;
	int			nbr_pt;
}				t_atof;

void			init_fractal(int argc, char *argv[], t_fractal *fractal);
void			init_mlx(t_fractal *fractal);
void			draw_mandelbrot(t_fractal *fractal);
int				calculate_julia(t_fractal *fractal);
void			draw_burning_ship(t_fractal *fractal);
int				calculate_mandelbrot(t_fractal *fractal);
void			draw_julia(t_fractal *fractal);
int				calculate_burning_ship(t_fractal *fractal);
int				ft_strcmp(char *s1, char *s2);
double			ft_atof(char *str);
int				exit_fractal(t_fractal *fractal);
void			img_pix_put(t_fractal *fractal, int x, int y, int col);
int				create_rgb(t_fractal *fractal);
int				mouse_hook(int button, int x, int y, t_fractal *fractal);
int				key_hook(int keycode, t_fractal *fractal);
void			draw(t_fractal *fractal);
char			*ft_strcpy(char *dest, char *src);
int				hf(t_fractal fractal);
int				ft_isdigit(int c);
int				check_float(char *str);
int				check_pnt(char *str);
int				check_valid(char *str);
int				check_digit(char *str);
int				is_good(char *str);
int				check_alpha(char *str);
int				check_digit(char *str);
int				ft_strlen(char *s);
void			keys(t_fractal *fractal, int keycode);
unsigned int	switch_colors(t_fractal *fractal, int i);
void			ft_parsing(t_fractal fractal);
double			ab(double d);

#endif