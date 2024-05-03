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

void draw(t_fractal *fractal)
{
    if(fractal->name[0] == 'j')
        draw_julia(fractal);
    else if(fractal->name[0] == 'm')
        draw_mandelbrot(fractal);
    else if(fractal->name[0] == 'b')
        draw_burning_ship(fractal);
}

int main(int argc, char *argv[])
{
        t_fractal fractal;
    if (argc < 2)
    {
        write(1, "mandelbrot/julia/burning_ship\n", 31);
        return (0);
    }
    init_fractal(&fractal, argv);
    init_mlx(&fractal);
    draw(&fractal);
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
        draw(&fractal);
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        fractal.real = atof(argv[2]);
        fractal.imaginary = atof(argv[3]);
        if (argc < 4)
        {
            write(1, "fractol julia real imaginary\n", 29);
            return (0);
        }
        draw(&fractal);
    }
    else if (ft_strcmp(argv[1], "burning_ship") == 0)
        draw(&fractal);
    else
    {
        write(2,"mandelbrot/julia/burning_ship\n", 31);
        return (0);
    }
    mlx_key_hook(fractal.win,key_hook, &fractal);
    mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
    mlx_hook(fractal.win, 17, 0, exit_fractal, &fractal);
    mlx_loop(fractal.mlx);
     return (0);
}
