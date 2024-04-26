/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:03:01 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/26 15:03:01 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void exit_fractal(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx, fractal->img);
    mlx_destroy_window(fractal->mlx, fractal->win);
    free(fractal->mlx);
    free(fractal);
    exit(1);
}
void	put_color_to_pixel(t_fractal *fractal)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(fractal->y * fractal->size_line / 4) + fractal->x] = fractal->color;
}