/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:03:14 by hichokri          #+#    #+#             */
/*   Updated: 2024/05/13 14:34:56 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_fractal *fractal)
{
	if (fractal->name[0] == 'j')
	{
		fractal->real = ft_atof(fractal->argv[2]);
		fractal->imaginary = ft_atof(fractal->argv[3]);
		if (fractal->real == -1 || fractal->imaginary == -1)
			exit(1);
		else
		{
			mlx_clear_window(fractal->mlx, fractal->win);
			draw_julia(fractal);
		}
	}
	else if (fractal->name[0] == 'm')
	{
		mlx_clear_window(fractal->mlx, fractal->win);
		draw_mandelbrot(fractal);
	}
	else if (fractal->name[0] == 'b')
	{
		mlx_clear_window(fractal->mlx, fractal->win);
		draw_burning_ship(fractal);
	}
}

void	ft_parsing(t_fractal fractal)
{
	if (fractal.argc == 4 && ft_strcmp(fractal.argv[1], "julia") == 0)
	{
		if (ft_strlen(fractal.name) > 5 || !is_good(fractal.argv[2])
			|| !is_good(fractal.argv[3]))
			exit(1);
	}
	else if (fractal.argc == 2 && ft_strcmp(fractal.argv[1], "mandelbrot") == 0)
	{
		if (ft_strlen(fractal.name) > 10)
			exit(1);
	}
	else if (fractal.argc == 2 && ft_strcmp(fractal.argv[1], "burning_ship") == 0)
	{
		if (ft_strlen(fractal.name) > 12)
			exit(1);
	}
	else
	{
		write(2, "mandelbrot\njulia | real | imaginaire\nburning_ship", 50);
		exit(1);
	}
}

int	hf(t_fractal fractal)
{
	if (fractal.argc == 2 && ft_strcmp(fractal.argv[1], "mandelbrot") == 0)
	{
		mlx_clear_window(fractal.mlx, fractal.win);
		draw(&fractal);
	}
	else if (fractal.argc == 4 && ft_strcmp(fractal.argv[1], "julia") == 0)
	{
		mlx_clear_window(fractal.mlx, fractal.win);
		draw(&fractal);
	}
	else if (fractal.argc == 2 && ft_strcmp(fractal.argv[1],
			"burning_ship") == 0)
	{
		mlx_clear_window(fractal.mlx, fractal.win);
		draw(&fractal);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (argc < 2)
	{
		write(2, "mandelbrot\njulia | real | imaginaire\nburning_ship", 50);
		exit(1); 
	}   
	init_fractal(argc, argv, &fractal);
	ft_parsing(fractal);
	init_mlx(&fractal);
	hf(fractal);
	mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_hook(fractal.win, 17, 0, exit_fractal, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
