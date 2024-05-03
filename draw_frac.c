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
    fractal->rgb.red = 19;
    fractal->rgb.green = 50;
    fractal->rgb.blue = 78;
    return (fractal->rgb.red << 16 | fractal->rgb.green << 8 |fractal->rgb.blue);
}

void img_pix_put(t_fractal *fractal,int x, int y, int col)
{
    char    *pixel;
    
    pixel = fractal->image.addr + (y * fractal->image.size_line + x * (fractal->image.bpp / 8));
     *(int *)pixel = col;
}

int calculate_mandelbrot(t_fractal *fractal)
{
    t_fractal c;
    t_fractal z;
    t_fractal tmp;
    int i;

    c.x = fractal->x / 500 * (fractal->x_max - fractal->x_min) + fractal->x_min;
    c.y = fractal->y / 500 * (fractal->y_max - fractal->y_min) + fractal->y_min;
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
        return(create_rgb(fractal) * i);
}

int calculate_julia(t_fractal *fractal)
{
    t_fractal c;
    t_fractal z;
    t_fractal tmp;
    int i;

    c.x = fractal->real;
    c.y = fractal->imaginary;
    z.x = fractal->x / 500 * (fractal->x_max - fractal->x_min) + fractal->x_min;
    z.y = fractal->y / 500 * (fractal->y_max - fractal->y_min) + fractal->y_min;
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
        return(create_rgb(fractal) * i);
}

int calculate_burning_ship(t_fractal *fractal)
{
    t_fractal c;
    t_fractal z;
    t_fractal tmp;
    int i;

    c.x = fractal->x / 500 * (fractal->x_max - fractal->x_min) + fractal->x_min;
    c.y = fractal->y / 500 * (fractal->y_max - fractal->y_min) + fractal->y_min;
    z.x = 0;
    z.y = 0;
    i = 0;

    while (z.x * z.x + z.y * z.y <= 4 && i < fractal->max_iter)
    {
        tmp.x = fabs(z.x * z.x - z.y * z.y + c.x);
        tmp.y = fabs(2 * z.x * z.y + c.y);
        z.x = tmp.x;
        z.y = tmp.y;
        i++;
    }
    
    if (i == fractal->max_iter)
        return(create_rgb(fractal));
    else
        return(create_rgb(fractal) * i);
}

void draw_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < 500)
	{
		while (fractal->y < 500)
		{
            
			img_pix_put(fractal, fractal->x, fractal->y,calculate_mandelbrot(fractal));
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
    mlx_put_image_to_window(fractal->mlx, fractal->win,fractal->image.img, 0, 0);

}

void draw_julia(t_fractal *fractal)
{
    fractal->x = 0;
    fractal->y = 0;
    while (fractal->x < 500)
    {
        while (fractal->y < 500)
        {
            img_pix_put(fractal,fractal->x, fractal->y, calculate_julia(fractal));
            fractal->y++;
        }
        fractal->x++;
        fractal->y = 0;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->image.img, 0, 0);
}

void draw_burning_ship(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < 500)
	{
		while (fractal->y < 500)
		{
            
			img_pix_put(fractal, fractal->x, fractal->y,calculate_burning_ship(fractal));
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
    mlx_put_image_to_window(fractal->mlx, fractal->win,fractal->image.img, 0, 0);

}

