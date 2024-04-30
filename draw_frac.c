/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:02:22 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/26 15:02:22 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int create_rgb(t_fractal *fractal)
{
    return (fractal->rgb->red << 16 | fractal->rgb->green << 8 |fractal->rgb->blue);
}

void img_pix_put(t_fractal *fractal, int col)
{
    char    *pixel;
    
    int x_offset = (int)(fractal->x * (fractal->image->bpp / 8));
    int y_offset = (int)(fractal->y * fractal->image->size_line);
    pixel = (char )(x_offset + y_offset) + fractal->image->addr;
    *(int *)pixel = col;
}

int calculate_mandelbrot(t_fractal *fractal)
{
    t_fractal c;
    t_fractal z;
    t_fractal tmp;
    int i;

    c.x = fractal->x / (WIDTH - 1) * (fractal->x_max - fractal->x_min) + fractal->x_min;
    c.y = fractal->y / (HEIGHT - 1) * (fractal->x_max - fractal->x_min) + fractal->x_min;
    z.x = 0;
    z.y = 0;
    i = 0;
    while (z.x * z.x + z.y * z.y <= 4 && i < fractal->max_iter)
    {
        tmp.x = z.x * z.x - z.y * z.y + c.x;
        tmp.y = 2 * z.x * z.y + c.y;
        z.x = tmp.x;
        z.y = tmp.y;
        i++;
    }
    if (i == fractal->max_iter)
        return(create_rgb(fractal));
    else
        return((create_rgb(fractal)) * i);
}

int calculate_julia(t_fractal *fractal)
{
    t_fractal c;
    t_fractal z;
    t_fractal tmp;
    int i;

    c.x = fractal->real;
    c.y = fractal->imaginary;
    tmp.x = z.x * z.x - z.y * z.y + c.x;
    tmp.y = 2 * z.x * z.y + c.y;
    z.x = tmp.x;
    z.y = tmp.y;
    i = 0;
    while (z.x * z.x + z.y * z.y <= 4 && i < fractal->max_iter)
    {
        tmp.x = z.x * z.x - z.y * z.y + c.x;
        tmp.y = 2 * z.x * z.y + c.y;
        z.x = tmp.x;
        z.y = tmp.y;
        i++;
    }
    if (i == fractal->max_iter)
        return(create_rgb(fractal));
    else
        return((create_rgb(fractal)) * i);
}

void draw_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HEIGHT)
		{
			img_pix_put(fractal,calculate_mandelbrot(fractal));
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
    mlx_put_image_to_window(fractal->mlx, fractal->win,fractal->image->img, fractal->x, fractal->y);

}

void draw_julia(t_fractal *fractal)
{
    fractal = malloc(sizeof(t_fractal));
    fractal->x = 0;
    fractal->y = 0;
    while (fractal->x < WIDTH)
    {
        while (fractal->y < HEIGHT)
        {
            img_pix_put(fractal, calculate_julia(fractal));
            fractal->y++;
        }
        fractal->x++;
        fractal->y = 0;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->image->img, fractal->x, fractal->y);
}