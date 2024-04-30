/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:03:14 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/26 15:03:14 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int main(int argc, char **argv)
{
    t_fractal *fractal;

    if (argc != 2)
    {
        write(1, "mandelbrot/julia\n", 17);
        return (0);
    }
    fractal = NULL;
    init_fractal(fractal);
    init_mlx(fractal);
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
        draw_mandelbrot(fractal);
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        if (argc != 4)
        {
            write(1, "fractol julia real imaginary\n", 29);
            return (0);
        }
        fractal->real = ft_atof(argv[2]);
        fractal->imaginary = ft_atof(argv[3]);
        if (fractal->real == 0 && fractal->imaginary == 0)
        {
            write(1, "fractol julia real imaginary\n", 29);
            return (0);
    }
        draw_julia(fractal);
    }
    else
    {
        write(1,"mandelbrot/julia\n", 17);
        return (0);
    }
    // mlx_key_hook(fractal->win,key_hook, fractal);
    // mlx_mouse_hook(fractal->win, mouse_hook, fractal);
    mlx_hook(fractal->win, 6, 1L << 6, exit_fractal, fractal);
    mlx_loop(fractal->mlx);
    return (0);
}