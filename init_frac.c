
#include "fractol.h"

void init_fractal(t_fractal *fractal)
{
    fractal->x1 = -2.0;
    fractal->x2 = 2.0;
    fractal->y1 = -2.0;
    fractal->y2 = 2.0;
    fractal->offset_x = 0;
    fractal->offset_y = 0;
    fractal->max_iter = 50;
    fractal->color = 0x000000;
}

void init_mlx(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractol");
    fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bpp, &fractal->line_len, &fractal->endian);
}