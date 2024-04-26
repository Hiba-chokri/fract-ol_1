#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
#include<X11/X.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
//define keycodes for linux
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 65451
# define KEY_MINUS 65453

//define mouse button codes for linux
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_fractal
{
    void	*mlx;
    void	*win;
    void	*img;
    char	*addr;
    int     scale;
    int		fractal;
    double	zoom;
    double	offset_x;
    double	offset_y;
    int		color;
    int		max_iter;
}				t_fractal;
typedef struct s_complex
{
    double x;
    double y;
    double real;
    double imaginary;
}              t_complex;

typedef struct s_color
{
    int r;
    int g;
    int b;
}              t_color;

void	init_fractal(t_fractal *fractal);
//draw mandelbrot fractal
void	draw_mandelbrot(t_fractal *fractal);
//draw julia fractal
void	draw_julia(t_fractal *fractal);
//draw burning ship fractal
void	draw_burning_ship(t_fractal *fractal);
//draw fractal main function
void	draw_fractal(t_fractal *fractal);
//mouse hook
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
//key hook
int		key_hook(int keycode, t_fractal *fractal);
//close window
int		close_window(t_fractal *fractal);
ft_strcmp(const char *s1, const char *s2);
double ft_atof(const char *str);
void exit_fractal(t_fractal *fractal);

#endif