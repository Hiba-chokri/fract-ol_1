/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/26 15:03:39 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/26 15:03:39 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


double	ft_atof(const char *str)
{
	double res;
	double dec_part;
	int divisor;
	int sign;
	int i;
	int j;
	int decimal_places;

	res = 0.0;
	dec_part = 0.0;
	sign = 1;
	i = 0;
	j = 0;
	decimal_places = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
		{
			sign = -1;
		}
	}
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		decimal_places = 1;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		dec_part = dec_part * 10 + (str[i] - '0');
		if (decimal_places)
			decimal_places++;
		i++;
	}
	if (decimal_places)
	{
		divisor = 1;
		while (j < decimal_places - 1)
		{
			divisor *= 10;
			j++;
		}
		dec_part /= divisor;
	}
	res += dec_part;
	return (res * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}