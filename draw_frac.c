/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:02:22 by hichokri          #+#    #+#             */
/*   Updated: 2024/05/16 21:01:13 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < VALUE)
	{
		while (fractal->y < VALUE)
		{
			img_pix_put(fractal, fractal->x, fractal->y,
				calculate_mandelbrot(fractal));
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	 mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->image.img, 0,	0);
}

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < VALUE)
	{
		while (fractal->y < VALUE)
		{
			img_pix_put(fractal, fractal->x, fractal->y,
				calculate_julia(fractal));
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->image.img, 0,
		0);
}

void	draw_burning_ship(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < VALUE)
	{
		while (fractal->y < VALUE)
		{
			img_pix_put(fractal, fractal->x, fractal->y,
				calculate_burning_ship(fractal));
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->image.img, 0,
		0);
}
