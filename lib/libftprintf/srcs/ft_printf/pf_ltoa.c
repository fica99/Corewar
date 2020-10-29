/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:03:07 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/29 21:46:33 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_strmemal(uintmax_t num, size_t *size_n, int base)
{
	*size_n = 1;
	while ((num = num / base))
		++(*size_n);
	return (ft_strnew((*size_n) + 5));
}

char				*ft_ultoa_base(uintmax_t n, int base, char cap)
{
	size_t			size_n;
	uintmax_t		num;
	char			*str;
	char			*ret;

	if (!(str = ft_strmemal(n, &size_n, base)))
		exit(1);
	ret = str;
	num = n;
	while (size_n--)
	{
		str[size_n] = num % base < 10 ? num % base + '0' :
										num % base + cap - 10;
		num /= base;
	}
	return (ret);
}

static void			pf_ltoa_rec(long num, char *str, int index)
{
	if (num >= 10)
		pf_ltoa_rec(num / 10, str, index - 1);
	str[index] = (num % 10) + '0';
}

char				*ft_iltoa(intmax_t num)
{
	int			str_size;
	char		*new_str;
	short		sign;
	intmax_t	tmp;

	if (num == LONG_MIN)
		return (ft_strdup("9223372036854775808"));
	sign = (num < 0) ? -1 : 1;
	num *= sign;
	str_size = 1;
	if (num)
	{
		tmp = num;
		while ((tmp /= 10) > 0)
			++str_size;
	}
	if (!(new_str = (char *)malloc(sizeof(char) * (str_size + 1))))
		return (NULL);
	new_str[str_size] = '\0';
	pf_ltoa_rec(num, new_str, str_size - 1);
	return (new_str);
}
