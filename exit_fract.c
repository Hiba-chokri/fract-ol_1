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
int exit_fractal(t_fractal *fractal, t_image *image)
{
    mlx_destroy_image(fractal->mlx, image->img);
    mlx_destroy_window(fractal->mlx, fractal->win);
    free(fractal->mlx);
    exit(1);
}
