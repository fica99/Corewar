/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 14:38:06 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/01 15:53:26 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double num, short pow)
{
	unsigned short	i;
	char			is_minus;
	double			res;

	is_minus = 0;
	if (pow < 0)
	{
		is_minus = 1;
		pow *= -1;
	}
	i = 0;
	res = 1;
	while (i < pow)
	{
		res *= num;
		++i;
	}
	if (is_minus)
		res = 1 / res;
	return (res);
}
