/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:06:45 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 21:56:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_spec_c(t_printf *pf)
{
	int			chrcter;
	char		buff[2];
	char		*str;

	chrcter = va_arg(pf->argptr, int);
	if (pf->flags & PF_FL_BIN)
	{
		str = pf_get_bits(sizeof(char), &chrcter);
		pf_add_str(pf, str);
		ft_strdel(&str);
	}
	else
	{
		buff[0] = chrcter;
		buff[1] = 0;
		pf_add_chr(pf, buff);
	}
}

void	pf_spec_s(t_printf *pf)
{
	char		*str;
	char		*bits;

	str = va_arg(pf->argptr, char*);
	if (pf->flags & PF_FL_BIN)
	{
		bits = pf_get_bits(ft_strlen(str) * sizeof(char), (void*)str);
		pf_add_str(pf, bits);
		ft_strdel(&bits);
	}
	else
		pf_add_str(pf, str);
}

void	pf_spec_percent(t_printf *pf)
{
	pf_add_str(pf, "%");
}

void	pf_spec_int(t_printf *pf)
{
	intmax_t	num;
	char		*str;

	if (pf->flags & PF_FL_PLUS)
		pf->flags &= ~PF_FL_SPACE;
	num = va_arg(pf->argptr, intmax_t);
	num = pf_convert_nb(pf->mod, num);
	if (pf->flags & PF_FL_BIN)
		str = pf_get_bits(pf_get_nb_size(pf->mod), &num);
	else
		str = ft_iltoa(num);
	pf_handle_di(pf, num, str);
}

void	pf_spec_p(t_printf *pf)
{
	intmax_t	num;
	char		*str;

	pf->flags &= ~PF_FL_SPACE;
	pf->flags &= ~PF_FL_PLUS;
	if (pf->flags & PF_FL_MINUS)
		pf->flags &= ~PF_FL_ZERO;
	num = va_arg(pf->argptr, intmax_t);
	str = ft_ultoa_base(num, (pf->flags & PF_FL_BIN) ? 2 : 16, 'a');
	pf_handle_p(pf, num, str);
}
