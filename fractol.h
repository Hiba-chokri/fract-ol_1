/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:03:23 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/26 15:03:23 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 600
# define HEIGHT 300
//define keycodes for linux
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
typedef struct s_image
{
    void *img;
    char *addr;
    int   bpp;
    int   size_line;
    int   endian;
} t_image; 

typedef struct s_rgb
{
    int red;
    int green;
    int blue;
} t_rgb;

typedef struct s_fractal
{
    void	*mlx;
   void     *win;
    int		max_iter;
    double x;
    double y;
    double x_min;
    double y_min;
    double x_max;
    double y_max;
    double real;
    double imaginary;
    int     color;
    t_image *image;
    t_rgb *rgb;
}				t_fractal;

void	init_fractal(t_fractal *fractal);
void    init_mlx(t_fractal *fractal);
void	draw_mandelbrot(t_fractal *fractal);
int     calculate_julia(t_fractal *fractal);
int     calculate_mandelbrot(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);
void	draw_fractal(t_fractal *fractal);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
void	put_color_to_pixel(t_fractal *fractal);
int		key_hook(int keycode, t_fractal *fractal);
int		close_window(t_fractal *fractal);
int     ft_strcmp(const char *s1, const char *s2);
double ft_atof(const char *str);
int exit_fractal(t_fractal *fractal, t_image *image);
void img_pix_put(t_fractal *fractal, int col);
int create_rgb(t_fractal *fractal);

#endif