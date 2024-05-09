/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:03:14 by hichokri          #+#    #+#             */
/*   Updated: 2024/05/09 23:57:56 by hichokri         ###   ########.fr       */
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
			exit(0);
		else
			draw_julia(fractal);
	}
	else if (fractal->name[0] == 'm')
		draw_mandelbrot(fractal);
	else if (fractal->name[0] == 'b')
		draw_burning_ship(fractal);
}
void ft_parsing(t_fractal fractal)
{
	if (fractal.name[0] == 'j')
	{
		if (ft_strlen(fractal.name) > 6 || !is_good(fractal.argv[2]) || !is_good(fractal.argv[3]) )
			exit(0);
	}
	else if (fractal.name[0]=='m')
	{
		if (ft_strlen(fractal.name) > 11)
			exit(0);
	}
	else if (fractal.name[0]=='b')
	{
		if (ft_strlen(fractal.name) > 13)
			exit(0);
	}
}
int	hf(t_fractal fractal)
{
	if (fractal.argc == 2 && ft_strcmp(fractal.argv[1], "mandelbrot") == 0)
		draw(&fractal);
	else if (fractal.argc == 4 && ft_strcmp(fractal.argv[1], "julia") == 0)
		draw(&fractal);
	else if (fractal.argc == 2 && ft_strcmp(fractal.argv[1], "burning_ship") == 0)
		draw(&fractal);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (argc < 2)
	{
		write(2, "mandelbrot\njulia | real | imaginaire\nburning_ship", 50);
		exit(0);
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
