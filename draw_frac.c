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

void calculate_mandelbrot(t_fractal *fractal)
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
        put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
    else
        put_color_to_pixel(fractal, fractal->x, fractal->y, fractal->color * i);
}

void calculate_julia(t_fractal *fractal)
{
    t_fractal c;
    t_fractal z;
    t_fractal tmp;
    int i;

    c.x = fractal->real;
    c.y = fractal->imaginary;
    z.x = fractal->x / fractal->zoom + fractal->offset_x;
    z.y = fractal->y / fractal->zoom + fractal->offset_y;
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
        put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
    else
        put_color_to_pixel(fractal, fractal->x, fractal->y, fractal->color * i);
}
void draw_mandelbrot(t_fractal *fractal)
{
    fractal = malloc(sizeof(t_fractal));
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HEIGHT)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}

void draw_julia(t_fractal *fractal)
{
    fractal = malloc(sizeof(t_fractal));
    fractal->x = 0;
    fractal->y = 0;
    while (fractal->x < WIDTH)
    {
        while (fractal->y < WIDTH)
        {
            calculate_julia(fractal);
            fractal->y++;
        }
        fractal->x++;
        fractal->y = 0;
    }
} 

// void draw_burning_ship(t_fractal *fractal)
// {
//     fractal = malloc(sizeof(t_fractal));
//     fractal->x = 0;
//     fractal->y = 0;
//     while (fractal->x < WIDTH)
//     {
//         while (fractal->y < HEIGHT)
//         {
//             calculate_burning_ship(fractal);
//             fractal->y++;
//         }
//         fractal->x++;
//         fractal->y = 0;
//     }

// }