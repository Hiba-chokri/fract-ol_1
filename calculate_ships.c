/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ships.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:00:33 by hichokri          #+#    #+#             */
/*   Updated: 2024/05/09 23:44:07 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot(t_fractal *fractal)
{
	t_fractal	c;
	t_fractal	z;
	t_fractal	tmp;
	int			i;

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
		return (0x0);
	else
		return (switch_colors(fractal,i));
}

int	calculate_julia(t_fractal *fractal)
{
	t_fractal	c;
	t_fractal	z;
	t_fractal	tmp;
	int			i;

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
		return (0x0);
	else
		return (switch_colors(fractal,i));
}

int	calculate_burning_ship(t_fractal *fractal)
{
	t_fractal	c;
	t_fractal	z;
	t_fractal	tmp;
	int			i;

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
		return (create_rgb(fractal));
	else
		return (create_rgb(fractal) * i);
}
