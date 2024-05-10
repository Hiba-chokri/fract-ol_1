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

void	ft_str(char *str, t_atof *ato, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		ato->dec_part = ato->dec_part * 10 + (str[i] - '0');
		if (ato->decimal_places)
			ato->decimal_places++;
		i++;
	}
}

void	ft_yf(t_atof *ato)
{
	int	j;

	j = 0;
	ato->divisor = 1;
	while (j < ato->decimal_places - 1)
	{
		ato->divisor *= 10;
		j++;
	}
	ato->dec_part /= ato->divisor;
}

double	ft_atof(char *str)
{
	int		i;
	t_atof	ato;

	ato.res = 0.0;
	i = 0;
	ato.dec_part = 0.0;
	ato.sign = 1;
	ato.decimal_places = 0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			ato.sign = -1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		ato.res = ato.res * 10 + (str[i++] - '0');
	if (str[i++] == '.')
		ato.decimal_places = 1;
	ft_str(str, &ato, i);
	if (ato.decimal_places)
		ft_yf(&ato);
	ato.res += ato.dec_part;
	return (ato.res * ato.sign);
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
