/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buff_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:17:18 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/29 21:35:23 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		pf_check_sign(t_printf *pf, intmax_t nb)
{
	char		sign;

	if (nb < 0)
		sign = ('-');
	else if (pf->flags & PF_FL_PLUS)
		sign = ('+');
	else if (pf->flags & PF_FL_SPACE)
		sign = (' ');
	else
		return (0);
	return (sign);
}

void		pf_add_symb(t_printf *pf, char c, size_t res_len)
{
	size_t	i;
	size_t	delta;

	i = 0;
	if ((delta = pf->width - res_len) > pf->width)
		delta = 0;
	while (i < delta)
	{
		pf->buff[(pf->buff_len)++] = c;
		i++;
	}
}

void		pf_add_str_2_buff(t_printf *pf, const char *str,
														const size_t len)
{
	size_t	i;

	i = 0;
	while (str[i] && i < len)
		pf->buff[pf->buff_len++] = str[i++];
}

void		pf_add_str(t_printf *pf, char *str)
{
	size_t	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	pf_check_mem(pf, pf->width + len);
	if (pf->prec >= 0 && len > (size_t)pf->prec)
		len = pf->prec;
	if (pf->flags & PF_FL_MINUS)
	{
		pf_add_str_2_buff(pf, str, len);
		pf_add_symb(pf, ' ', len);
	}
	else
	{
		pf_add_symb(pf, pf->flags & PF_FL_ZERO ? '0' : ' ', len);
		pf_add_str_2_buff(pf, str, len);
	}
}

void		pf_check_mem(t_printf *pf, const size_t add_len)
{
	while (pf->buff_len + add_len >= pf->malloc_len)
	{
		if (!(pf->buff = ft_realloc((void*)pf->buff, pf->malloc_len,
				(pf->malloc_len * 2))))
			exit(1);
		pf->malloc_len *= 2;
	}
}
