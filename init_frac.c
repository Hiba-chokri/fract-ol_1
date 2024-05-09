/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:03:31 by hichokri          #+#    #+#             */
/*   Updated: 2024/05/09 23:22:24 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(int argc, char *argv[], t_fractal *fractal)
{
	fractal->x_min = -2.0;
	fractal->x_max = 2.0;
	fractal->y_min = -2.0;
	fractal->y_max = 2.0;
	fractal->max_iter = 100;
	fractal->iter = 0;
	fractal->c = 'x';
	fractal->argv = argv;
	fractal->argc = argc;
	ft_strcpy(fractal->name, fractal->argv[1]);
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, 500, 500, "Fractol");
	fractal->image.img = mlx_new_image(fractal->mlx, 500, 500);
	fractal->image.addr = mlx_get_data_addr(fractal->image.img,
			&fractal->image.bpp, &fractal->image.size_line,
			&fractal->image.endian);
}
