/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoa_round.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:55:39 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/13 20:13:39 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_dtoa_round_add(char **str, size_t i, size_t prec)
{
	size_t	size;

	if (!prec)
		(*str)[i - 2] += 1;
	else
		(*str)[i + prec - 1] += 1;
	size = i + prec;
	pf_carry(*str + 1, size, TRUE);
	pf_dig_overflow(str, 1, &size, TRUE);
}

static void			pf_dtoa_round_cut(char **str, size_t i, size_t prec)
{
	char	*num;
	size_t	j;

	num = *str;
	if (num[i + prec] > '5')
		pf_dtoa_round_add(str, i, prec);
	else if (num[i + prec] == '5')
	{
		j = i + prec;
		while (num[++j])
		{
			if (num[j] > '0')
			{
				pf_dtoa_round_add(str, i, prec);
				return ;
			}
		}
		if (!num[j])
			if (num[i - 2] % 2)
				pf_dtoa_round_add(str, i, prec);
	}
}

size_t				pf_dtoa_round(char **str, size_t prec)
{
	char	*num;
	size_t	i;
	size_t	j;

	num = *str;
	i = 0;
	while (num[i] != '.')
		++i;
	j = 0;
	++i;
	while (num[i + j] && j < prec)
		++j;
	if (!num[i + j])
		ft_memset(*str + i + j, '0', prec - j);
	else
		pf_dtoa_round_cut(str, i, prec);
	num = ft_strchr(*str, '.');
	i = num - *str;
	if (!prec)
		(*str)[i] = '\0';
	else
		(*str)[++i + prec] = '\0';
	return (i + prec);
}
