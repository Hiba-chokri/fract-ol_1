/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:16:32 by hichokri          #+#    #+#             */
/*   Updated: 2024/05/16 20:58:04 by hichokri         ###   ########.fr       */
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
	if (keycode == 53)
		exit_fractal(fractal);
	if (keycode == 69)
		fractal->max_iter += 10;
	if (keycode == 78)
		fractal->max_iter -= 10;
}

int	key_hook(int keycode, t_fractal *fractal)
{
	keys(fractal, keycode);
	if (keycode == 123)
	{
		fractal->x_max += fractal->cheft;
		fractal->x_min += fractal->cheft;
	}
	if (keycode == 124)
	{
		fractal->x_max -= fractal->cheft;
		fractal->x_min -= fractal->cheft;
	}
	if (keycode == 126)
	{
		fractal->y_min += fractal->cheft;
		fractal->y_max += fractal->cheft;
	}
	if (keycode == 125)
	{
		fractal->y_max -= fractal->cheft;
		fractal->y_min -= fractal->cheft;
	}
	mlx_clear_window(fractal->mlx, fractal->win);
	draw(fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	double	x_mous;
	double	y_mous;

	x_mous = x * (fractal->x_max - fractal->x_min) / VALUE + fractal->x_min;
	y_mous = y * (fractal->y_max - fractal->y_min) / VALUE + fractal->y_min;
	if (button == 4)
	{
		fractal->x_min = x_mous + (fractal->x_min - x_mous) / 0.5;
		fractal->x_max = x_mous + (fractal->x_max - x_mous) / 0.5;
		fractal->y_min = y_mous + (fractal->y_min - y_mous) / 0.5;
		fractal->y_max = y_mous + (fractal->y_max - y_mous) / 0.5;
		fractal->iter--;
		fractal->cheft /= 0.5;
	}
	if (button == 5 && fractal->iter < 49)
	{
		fractal->x_min = x_mous + (fractal->x_min - x_mous) * 0.5;
		fractal->x_max = x_mous + (fractal->x_max - x_mous) * 0.5;
		fractal->y_max = y_mous + (fractal->y_max - y_mous) * 0.5;
		fractal->y_min = y_mous + (fractal->y_min - y_mous) * 0.5;
		fractal->iter++;
		fractal->cheft *= 0.5;
	}
	draw(fractal);
	return (0);
}
