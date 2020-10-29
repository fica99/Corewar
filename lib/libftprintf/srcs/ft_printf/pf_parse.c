/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:38:24 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 21:56:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_parse_flags(const char *format,
									t_printf *pf)
{
	t_pf_flags	tmp;

	pf->flags = PF_FL_INIT;
	while (format[pf->i])
	{
		tmp = pf_flags_table()[(size_t)format[++(pf->i)]];
		if (!tmp)
			break ;
		pf->flags |= tmp;
	}
}

static void	pf_parse_width(const char *format, t_printf *pf)
{
	pf->width = 0;
	if (ft_isdigit(format[pf->i]))
	{
		pf->width = ft_atoi(format + pf->i);
		while (ft_isdigit(format[++pf->i]))
			;
	}
}

static void	pf_parse_precision(const char *format,
												t_printf *pf)
{
	pf->prec = -1;
	if (format[pf->i] == '.')
	{
		if (ft_isdigit(format[++(pf->i)]))
		{
			pf->prec = ft_atoi(format + pf->i);
			while (ft_isdigit(format[++pf->i]))
				;
		}
		else
			pf->prec = 0;
	}
}

static void	pf_parse_mod(const char *format, t_printf *pf)
{
	t_pf_mod_len	tmp;

	pf->mod = PF_ML_INIT;
	while (format[(pf->i)])
	{
		tmp = pf_mod_table()[(size_t)format[pf->i]];
		if (pf->mod == PF_ML_H && tmp == PF_ML_H)
			pf->mod = PF_ML_HH;
		else if (pf->mod == PF_ML_L && tmp == PF_ML_L)
			pf->mod = PF_ML_LL;
		else if (tmp)
			pf->mod = tmp;
		else
			return ;
		++(pf->i);
	}
}

void		pf_parse_string(const char *format, t_printf *pf)
{
	void	(*f)(t_printf *pf);

	if (format[pf->i] == '%')
	{
		pf_parse_flags(format, pf);
		pf_parse_width(format, pf);
		pf_parse_precision(format, pf);
		pf_parse_mod(format, pf);
		pf_parse_undefined(format, pf);
		if (!format[pf->i])
			return ;
		if ((f = pf_spec_table(format[(pf->i)++])))
			f(pf);
		return ;
	}
	else if (format[pf->i] == '{')
		if (pf_parse_color(format, pf))
			return ;
	pf_check_mem(pf, 1);
	pf->buff[(pf->buff_len)++] = format[(pf->i)++];
}
