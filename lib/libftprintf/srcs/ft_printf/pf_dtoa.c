/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:17:32 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/19 16:16:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double		pf_swap_bytes(long double num)
{
	unsigned char	*bites;
	unsigned char	*res_bites;
	long double		res;
	size_t			i;

	bites = (unsigned char*)&num;
	res_bites = (unsigned char*)&res;
	i = 0;
	while (i < 10)
	{
		res_bites[i] = bites[9 - i];
		++i;
	}
	return (res);
}

static short			pf_get_exp(unsigned char *bites)
{
	short	exp;

	exp = bites[0] & DEL_SIGN;
	exp <<= 8;
	exp = (exp | bites[1]) - LONG_DOUBLE_EXP;
	return (exp);
}

static unsigned long	pf_get_mantis(unsigned char *bites)
{
	unsigned long	res;
	unsigned char	*res_bites;
	size_t			i;

	res = 0;
	res_bites = (unsigned char*)&res;
	i = 0;
	while (i < 8)
	{
		res_bites[i] = bites[i];
		++i;
	}
	return (res);
}

static char				pf_is_correct_double(char *str, short exp, long mantis)
{
	if (exp - 1 == LONG_DOUBLE_EXP)
	{
		if (mantis == INF_MANTIS)
			ft_strcpy(str + 1, "inf");
		else if (mantis)
			ft_strcpy(str, "nan");
		return (FALSE);
	}
	return (TRUE);
}

size_t					pf_dtoa(char **str, long double nb, int prec)
{
	uint8_t			sign;
	short			exp;
	unsigned long	mantis;
	unsigned char	*bites;
	char			*num;

	nb = pf_swap_bytes(nb);
	bites = (unsigned char*)&nb;
	sign = (bites[0] & (1 << 7));
	exp = pf_get_exp(bites);
	mantis = pf_get_mantis(bites + 2);
	if (!(num = (char*)malloc(LONG_DOUBLE_MALLOC_LEN + prec)))
		exit(EXIT_FAILURE);
	*str = num;
	sign ? ft_strcpy(num, "-") : ft_strcpy(num, "+");
	if (!pf_is_correct_double(num, exp, mantis))
	{
		if (num[0] == 'n')
			return (3);
		return (4);
	}
	pf_exp_mantis2str(num + 1, exp, mantis);
	return (pf_dtoa_round(str, prec));
}
