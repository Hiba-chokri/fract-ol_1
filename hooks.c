/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:16:32 by hichokri          #+#    #+#             */
/*   Updated: 2024/05/10 10:36:03 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
}

void	keys(t_fractal *fractal, int keycode)
{
	if (keycode == 7)
		fractal->c = 'x';
	if (keycode == 15)
		fractal->c = 'r';
	if (keycode == 35)
		fractal->c = 'p';
}

int	key_hook(int keycode, t_fractal *fractal)
{
	keys(fractal, keycode);
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
	double	x_mous;
	double	y_mous;

	x_mous = x * (fractal->x_max - fractal->x_min) / 500 + fractal->x_min;
	y_mous = y * (fractal->y_max - fractal->y_min) / 500 + fractal->y_min;
	if (button == 4)
	{
		fractal->x_min = x_mous + (fractal->x_min - x_mous) / 0.5;
		fractal->x_max = x_mous + (fractal->x_max - x_mous) / 0.5;
		fractal->y_min = y_mous + (fractal->y_min - y_mous) / 0.5;
		fractal->y_max = y_mous + (fractal->y_max - y_mous) / 0.5;
		fractal->iter--;
	}
	if (button == 5 && fractal->iter < 55)
	{
		fractal->x_min = x_mous + (fractal->x_min - x_mous) * 0.5;
		fractal->x_max = x_mous + (fractal->x_max - x_mous) * 0.5;
		fractal->y_max = y_mous + (fractal->y_max - y_mous) * 0.5;
		fractal->y_min = y_mous + (fractal->y_min - y_mous) * 0.5;
		fractal->iter++;
	}
	draw(fractal);
	return (0);
}
