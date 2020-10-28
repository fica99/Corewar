/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_handlers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:50:16 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 21:56:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_spec_x(t_printf *pf, char is_big)
{
	intmax_t	num;
	char		*str;

	pf->flags &= ~PF_FL_SPACE;
	pf->flags &= ~PF_FL_PLUS;
	if (pf->flags & PF_FL_MINUS)
		pf->flags &= ~PF_FL_ZERO;
	num = va_arg(pf->argptr, intmax_t);
	num = pf_convert_unb(pf->mod, num);
	str = ft_ultoa_base(num, (pf->flags & PF_FL_BIN) ? 2 : 16,
												(is_big) ? 'A' : 'a');
	pf_handle_x(pf, num, str, is_big);
}

void			pf_spec_big_x(t_printf *pf)
{
	pf_spec_x(pf, 1);
}

void			pf_spec_small_x(t_printf *pf)
{
	pf_spec_x(pf, 0);
}

void			pf_spec_uint(t_printf *pf)
{
	intmax_t	num;
	char		*str;

	num = va_arg(pf->argptr, intmax_t);
	num = pf_convert_unb(pf->mod, num);
	if (pf->flags & PF_FL_BIN)
		str = pf_get_bits(pf_get_unb_size(pf->mod), &num);
	else
		str = ft_iltoa(num);
	pf_handle_u(pf, num, str);
}

void			pf_spec_o(t_printf *pf)
{
	intmax_t	num;
	char		*str;

	pf->flags &= ~PF_FL_SPACE;
	pf->flags &= ~PF_FL_PLUS;
	if (pf->flags & PF_FL_MINUS)
		pf->flags &= ~PF_FL_ZERO;
	num = va_arg(pf->argptr, intmax_t);
	num = pf_convert_unb(pf->mod, num);
	str = ft_ultoa_base(num, (pf->flags & PF_FL_BIN) ? 2 : 8, '0');
	pf_handle_o(pf, num, str);
}
