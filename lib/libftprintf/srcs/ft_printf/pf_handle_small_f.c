/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_small_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:00:28 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 21:56:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_double_invalid_str(t_printf *pf, char *str_num, size_t len)
{
	char	sign;

	pf_check_mem(pf, len + pf->width);
	sign = 0;
	if (str_num[0] != 'n')
	{
		sign = pf_check_sign(pf, str_num[0] == '+' ? 1 : -1);
		if (!sign)
			--len;
	}
	if (sign && sign != '-' && (pf->flags & PF_FL_ZERO))
		pf->buff[pf->buff_len++] = sign;
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_symb(pf, ' ', len);
	if ((sign && !(pf->flags & PF_FL_ZERO)) || sign == '-')
		pf->buff[pf->buff_len++] = sign;
	if (str_num[0] != 'n')
		++str_num;
	pf_add_str_2_buff(pf, str_num, len);
	if (pf->flags & PF_FL_MINUS)
		pf_add_symb(pf, ' ', len);
}

static void	pf_double_handle_flags(t_printf *pf, char *str_num, size_t len)
{
	char	sign;

	pf_check_mem(pf, len + pf->width + 3);
	sign = pf_check_sign(pf, str_num[0] == '+' ? 1 : -1);
	if (!sign)
		--len;
	if (sign && (pf->flags & PF_FL_ZERO))
		pf->buff[pf->buff_len++] = sign;
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_symb(pf, (pf->flags & PF_FL_ZERO) ? '0' : ' ', len);
	if (sign && !(pf->flags & PF_FL_ZERO))
		pf->buff[pf->buff_len++] = sign;
	pf_add_str_2_buff(pf, ++str_num, len);
	if ((pf->flags & PF_FL_HASH) && !pf->prec)
	{
		pf_add_str_2_buff(pf, ".", ++len);
	}
	if (pf->flags & PF_FL_MINUS)
		pf_add_symb(pf, ' ', len);
}

void		pf_spec_small_f(t_printf *pf)
{
	long double	num;
	char		*str_num;
	size_t		len;

	num = ((pf->mod == PF_ML_BL) ? va_arg(pf->argptr, long double) :
											va_arg(pf->argptr, double));
	if (pf->flags & PF_FL_BIN)
	{
		str_num = pf_get_bits(10, &num);
		pf_add_str(pf, str_num);
	}
	else
	{
		if (pf->prec == -1)
			pf->prec = 6;
		if (pf->flags & PF_FL_PLUS)
			pf->flags &= ~PF_FL_SPACE;
		len = pf_dtoa(&str_num, num, pf->prec);
		(!ft_isdigit(str_num[1])) ? pf_double_invalid_str(pf, str_num, len) :
						pf_double_handle_flags(pf, str_num, len);
	}
	ft_strdel(&str_num);
}
