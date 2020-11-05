/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:32:42 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 01:55:01 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		atoi_check_int(const char *str)
{
	int				i;
	long			nbr;
	int				negative;
	int				x;

	i = 0;
	nbr = 0;
	negative = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	(str[i] == '-') ? negative *= -1 : negative;
	if (str[i] == '-' || str[i] == '+')
		i++;
	x = 0;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + str[i++] - 48;
		if (nbr != 0)
			x++;
	}
	nbr = nbr * negative;
	if (nbr > 2147483647 || nbr < -2147483648 || x > 9 || nbr < 0)
		ft_exit("Error");
	return ((int)nbr);
}

int		is_str_digits(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i++])))
			return (0);
	}
	return (1);
}

int		is_int(char *str)
{
	if (!is_str_digits(str))
		return (0);
	else
		atoi_check_int(str);
	return (1);
}
