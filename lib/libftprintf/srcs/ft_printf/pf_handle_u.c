/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 10:18:43 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/28 21:56:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	pf_pre_u(t_printf *pf, intmax_t nb, size_t len)
{
	char		sign;
	size_t		res_len;
	char		is_prec;

	if ((int)len < pf->prec || (!pf->prec && !nb))
		res_len = pf->prec;
	else
		res_len = len;
	sign = pf_check_sign(pf, nb);
	is_prec = (pf->flags & PF_FL_ZERO) && pf->prec == -1;
	if (sign && is_prec)
		pf->buff[pf->buff_len++] = sign;
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_symb(pf, is_prec ? '0' : ' ', res_len);
	if (sign && !is_prec)
		pf->buff[pf->buff_len++] = sign;
	while (len++ < res_len)
		pf->buff[pf->buff_len++] = '0';
	return (res_len);
}

void			pf_handle_u(t_printf *pf, intmax_t nb, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	pf_check_mem(pf, pf->width + len + 1);
	len = pf_pre_u(pf, nb, len);
	pf_add_str_2_buff(pf, str, len);
	if (pf->flags & PF_FL_MINUS)
		pf_add_symb(pf, ' ', len);
	ft_strdel(&str);
}
