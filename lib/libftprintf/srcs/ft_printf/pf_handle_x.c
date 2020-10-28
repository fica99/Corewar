/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:11:00 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 21:56:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_print_prefix(t_printf *pf, intmax_t nb, char is_big)
{
	if (pf->flags & PF_FL_HASH && nb)
	{
		pf->buff[pf->buff_len++] = '0';
		if (is_big)
			pf->buff[pf->buff_len++] = 'X';
		else
			pf->buff[pf->buff_len++] = 'x';
	}
}

static void		pf_check_prefix(t_printf *pf, intmax_t nb)
{
	if (pf->flags & PF_FL_HASH && nb)
		if (pf->width - 2 < pf->width)
			pf->width -= 2;
}

static size_t	pf_pre_x(t_printf *pf, intmax_t nb, size_t len,
																char is_big)
{
	char		sign;
	size_t		res_len;
	char		is_prec;

	if ((int)len < pf->prec || (!pf->prec && !nb))
		res_len = pf->prec;
	else
		res_len = len;
	sign = pf_check_sign(pf, nb);
	pf_check_prefix(pf, nb);
	is_prec = (pf->flags & PF_FL_ZERO) && pf->prec == -1;
	if (sign && is_prec)
		pf->buff[pf->buff_len++] = sign;
	if (is_prec)
		pf_print_prefix(pf, nb, is_big);
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_symb(pf, is_prec ? '0' : ' ', res_len);
	if (sign && !is_prec)
		pf->buff[pf->buff_len++] = sign;
	if (!is_prec)
		pf_print_prefix(pf, nb, is_big);
	while (len++ < res_len)
		pf->buff[pf->buff_len++] = '0';
	return (res_len);
}

void			pf_handle_x(t_printf *pf, intmax_t nb, char *str,
															char is_big)
{
	size_t	len;

	len = ft_strlen(str);
	pf_check_mem(pf, pf->width + len + 1);
	len = pf_pre_x(pf, nb, len, is_big);
	pf_add_str_2_buff(pf, str, len);
	if (pf->flags & PF_FL_MINUS)
		pf_add_symb(pf, ' ', len);
	ft_strdel(&str);
}
