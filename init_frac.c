/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:03:31 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/26 15:03:31 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fractal(t_fractal *fractal)
{
    fractal->x_min = -2.0;
    fractal->x_max = 2.0;
    fractal->y_min = -2.0;
    fractal->y_max = 2.0;
    fractal->offset_x = 0;
    fractal->offset_y = 0;
    fractal->max_iter = 50;
    fractal->color = 0x000000;
}

void init_mlx(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractol");
    fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bpp, &fractal->line_len, &fractal->endian);
}