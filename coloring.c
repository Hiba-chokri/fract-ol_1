/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:59:16 by hichokri          #+#    #+#             */
/*   Updated: 2024/05/14 16:22:38 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_rgb(t_fractal *fractal)
{
	return (fractal->rgb.red << 16 | fractal->rgb.green << 8
		| fractal->rgb.blue);
}

void	img_pix_put(t_fractal *fractal, int x, int y, int col)
{
	char	*pixel;

	pixel = fractal->image.addr + (y * fractal->image.size_line + x
			* (fractal->image.bpp / 8));
	*(int *)pixel = col;
}

void	switching(t_fractal *fractal)
{
	int	x;

	x = 0;
	if (fractal->c == '+')
	{
		while (x < fractal->max_iter)
		{
			fractal->rgb.red = 2.55 * x;
			fractal->rgb.green = 2.55 * x;
			fractal->rgb.blue = 2.55 * x;
			x++;
		}
	}
	if (fractal->c == '-')
	{
		x = fractal->max_iter;
		while (x > 0)
		{
			fractal->rgb.red = 2.55 * x;
			fractal->rgb.green = 2.55 * x;
			fractal->rgb.blue = 2.55 * x;
			x--;
		}
	}
}

unsigned int	switch_colors(t_fractal *fractal, int i)
{
	switching(fractal);
	if (fractal->c == 'r')
	{
		fractal->rgb.red = 2.55 * i;
		fractal->rgb.green = 2.55 * i;
		fractal->rgb.blue = 2.55 * i;
	}
	if (fractal->c == 'x')
	{
		fractal->rgb.red = 9;
		fractal->rgb.green = 2.55 * i;
		fractal->rgb.blue = 2.55 * i;
	}
	if (fractal->c == 'p')
	{
		fractal->rgb.red = 2.55 * i;
		fractal->rgb.green = 0;
		fractal->rgb.blue = 2.55 * i;
	}
	return (create_rgb(fractal));
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
