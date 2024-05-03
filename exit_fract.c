/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/26 15:03:01 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/26 15:03:01 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
}

int	key_hook(int keycode, t_fractal *fractal)
{
	printf("%d   \n", keycode);
	if (keycode == 53)
		exit_fractal(fractal);
	if (keycode == 123)
	{
		fractal->x_max += 0.5;
		fractal->x_min += 0.5;
	}
	if (keycode == 124)
	{
		fractal->x_max -= 0.5;
		fractal->x_min -= 0.5;
	}
	if (keycode == 126)
	{
		fractal->y_min += 0.5;
		fractal->y_max += 0.5;
	}
	if (keycode == 125)
	{
		fractal->y_max -= 0.5;
		fractal->y_min -= 0.5;
	}
	draw(fractal);
	// draw_julia(fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	// printf("%d   \n", button);
	printf("%d %d\n", x, y);

	if (button == 5)
	{
		fractal->x_min /= 0.5;
		fractal->x_max /= 0.5;
		fractal->y_max /= 0.5;
		fractal->y_min /= 0.5;
	}
	if (button == 4)
	{
		fractal->x_min *= 0.5;
		fractal->x_max *= 0.5;
		fractal->y_max *= 0.5;
		fractal->y_min *= 0.5;
	}
	draw(fractal);
	// draw_mandelbrot(fractal);
	// draw_julia(fractal);
	return (0);
}