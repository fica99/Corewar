/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:23:40 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/01 15:15:06 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number_len(int n)
{
	int	a;
	int	i;

	a = n;
	i = 0;
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	if (n == 0)
		return (1);
	return (i);
}

char			*ft_itoa(int n)
{
	char	*nb;
	int		i;
	int		a;

	i = number_len(n);
	a = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648\0"));
	if (n < 0)
	{
		a = -n;
		i++;
	}
	if (!(nb = ft_strnew(i)))
		return (NULL);
	if (n < 0)
		nb[0] = '-';
	if (n == 0)
		nb[0] = '0';
	while (a != 0)
	{
		nb[--i] = a % 10 + '0';
		a = a / 10;
	}
	return (nb);
}
