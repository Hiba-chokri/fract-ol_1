/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:28:19 by hichokri          #+#    #+#             */
/*   Updated: 2024/05/15 20:25:29 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	check_pnt(char *str)
{
	int	nbr_pt;

	nbr_pt = 0;
	while (*str)
	{
		if (*str == '.')
			nbr_pt++;
		str++;
	}
	if (nbr_pt > 1)
		return (0);
	return (1);
}

int	check_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == '\0')
				return (1);
		}
		i++;
	}
	return (1);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '.' && str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_good(char *str)
{
	if (!check_pnt(str))
		return (0);
	if (!check_valid(str))
		return (0);
	if (!check_digit(str))
		return (0);
	return (1);
}
