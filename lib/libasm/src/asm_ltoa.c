/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_ltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:21:46 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/20 15:34:45 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	asm_digit(long long num)
{
	int	digit;

	digit = 1;
	if (!num)
		return (digit);
	while ((num /= 10) > 0)
		digit++;
	return (digit);
}

static void	asm_ltoa_rec(long num, char *str, int index)
{
	if (num >= 10)
		asm_ltoa_rec(num / 10, str, index - 1);
	str[index] = (num % 10) + '0';
}

char		*asm_ltoa(long long num)
{
	int		str_size;
	char	*new_str;
	short	sign;

	sign = (num < 0) ? -1 : 1;
	num *= sign;
	str_size = asm_digit(num);
	if (sign == -1)
		str_size++;
	if (!(new_str = (char *)malloc(sizeof(char) * (str_size + 1))))
		return (NULL);
	new_str[str_size] = '\0';
	if (sign == -1)
		new_str[0] = '-';
	asm_ltoa_rec(num, new_str, str_size - 1);
	return (new_str);
}
