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
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	printf("%d %d\n", x, y);

	double x_mous, y_mous;
	x_mous = x * (fractal->x_max - fractal->x_min) / 500 + fractal->x_min;
    y_mous = y * (fractal->y_max - fractal->y_min) / 500 + fractal->y_min;
	if (button == 4)
	{
		fractal->x_min = x_mous + (fractal->x_min - x_mous) / 0.5;
		fractal->x_max = x_mous + (fractal->x_max - x_mous) / 0.5;
		fractal->y_min = y_mous + (fractal->y_min - y_mous) / 0.5;
		fractal->y_max = y_mous + (fractal->y_max - y_mous) / 0.5;
	}
	if (button == 5)
	{
		fractal->x_min = x_mous + (fractal->x_min - x_mous) * 0.5;
		fractal->x_max = x_mous + (fractal->x_max - x_mous) * 0.5;
		fractal->y_max = y_mous + (fractal->y_max - y_mous) * 0.5;
		fractal->y_min = y_mous + (fractal->y_min - y_mous) * 0.5;
	}
	draw(fractal);

	// if (button == 5)
	// {
	// 	fractal->x_min /= 0.5;
	// 	fractal->x_max /= 0.5;
	// 	fractal->y_max /= 0.5;
	// 	fractal->y_min /= 0.5;
	// }
	// if (button == 4)
	// {
	// 	fractal->x_min *= 0.5;
	// 	fractal->x_max *= 0.5;
	// 	fractal->y_max *= 0.5;
	// 	fractal->y_min *= 0.5;
	// }
	// draw(fractal);
	return (0);
}