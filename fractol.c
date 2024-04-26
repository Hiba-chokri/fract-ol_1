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
    t_fractal fractal;

    if (argc != 2)
    {
        write(1, "mandelbrot/julia/burning_ship\n", 51);
        return (0);
    }
    fractal = malloc(sizeof(t_fractal));
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
        draw_mandelbrot(&fractal);
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        if (argc != 4)
        {
            write(1, "fractol julia real imaginary\n", 42);
            return (0);
        }
        fractal.real = ft_atof(argv[2]);
        fractal.imaginary = ft_atof(argv[3]);
        if (fractal.real == 0 && fractal.imaginary == 0)
        {
            write(1, "fractol julia real imaginary\n", 42);
            return (0);
    }
        draw_julia(&fractal);
    }
    else if (ft_strcmp(argv[1], "burning_ship") == 0)
        draw_burning_ship(&fractal);
    else
    {
        write(1,"fractol mandelbrot/julia/burning_ship\n", 51);
        return (0);
    }
    if (fractal.fractal == 0)
    {
        write(1, "mandelbrot/julia/burning_ship\n", );
        return (0);
    }
    init_fractal(&fractal);
    init_mlx(&fractal);
    draw_fractal(&fractal);
    mlx_key_hook(fractal.win, 2, 1L << 0, key_hook, &fractal);
    mlx_mouse_hook(fractal.win, 4, 1L << 2, mouse_hook, &fractal);
    mlx_hook(fractal.win, 6, 1L << 6, exit_fract(&fractal), &fractal);
    mlx_loop(fractal.mlx);
    return (0);
}