/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoa_long_arith.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:29:37 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/12 23:53:19 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_carry(char *res, int size, char is_str)
{
	size_t	nb;

	nb = 0;
	if (is_str)
		nb = 48;
	while (--size)
	{
		if (is_str && res[size] == '.')
			continue ;
		if (res[size] - nb > 9)
		{
			if (res[size - 1] == '.')
				res[size - 2] += (res[size] - nb) / 10;
			else
				res[size - 1] += (res[size] - nb) / 10;
			res[size] = (res[size] - nb) % 10 + nb;
		}
	}
}

static void		pf_exp(char *res, int size, short pow)
{
	int tmp;

	tmp = size;
	while (--tmp >= 0)
		res[tmp] *= pow;
	pf_carry(res, size, FALSE);
}

char			*pf_pow(short pow, short exp)
{
	char			*res;
	int				size;
	double			new_pow;

	if (exp < 0)
	{
		exp = ft_abs(exp);
		new_pow = 10.0 / pow;
		size = log10(new_pow) * exp + 1 + (int)(log10(pow) * exp);
		pow = new_pow;
	}
	else
		size = log10(pow) * ft_abs(exp) + 1;
	if (!(res = ft_strnew(size)))
		exit(EXIT_FAILURE);
	res[size - 1] = 1;
	while (exp--)
		pf_exp(res, size, pow);
	return (res);
}

char			*pf_div_pow(char *num, short prev_exp, short exp, short pow)
{
	size_t	len;
	size_t	j;
	int		tmp;
	char	*res;
	short	div;

	div = (short)ft_pow(pow, ft_abs(prev_exp - exp));
	if (!(res = ft_strnew(log10(pow) * exp + 1)))
		exit(EXIT_FAILURE);
	tmp = *num;
	len = log10(pow) * prev_exp + 1;
	while (tmp < div && len--)
		tmp = tmp * 10 + *(++num);
	j = 0;
	while (len--)
	{
		res[j++] = tmp / div;
		tmp = tmp % div;
		tmp = tmp * 10 + *(++num);
	}
	return (res);
}
