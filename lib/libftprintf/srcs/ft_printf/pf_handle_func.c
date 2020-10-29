/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:30:05 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/28 21:56:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_align_to_width(t_printf *pf, char c, t_len_opts *len_opts)
{
	size_t	i;

	i = len_opts->ac_len;
	while (i < len_opts->w_len)
	{
		pf->buff[(pf->buff_len)++] = c;
		i++;
	}
}

void	pf_align_to_accuracy(t_printf *pf, char c,
	t_len_opts *len_opts)
{
	size_t	i;

	i = len_opts->num_len;
	while (i < len_opts->ac_len)
	{
		pf->buff[(pf->buff_len)++] = c;
		i++;
	}
}

void	pf_add_chr(t_printf *pf, char *str)
{
	size_t	len;

	if (!str)
		str = "(null)";
	len = 1;
	pf_check_mem(pf, pf->width + len);
	if (pf->prec >= 0 && len > (size_t)pf->prec)
		len = pf->prec;
	if (pf->flags & PF_FL_MINUS)
	{
		pf_add_chr_2_buff(pf, *str);
		pf_add_symb(pf, ' ', len);
	}
	else
	{
		pf_add_symb(pf, pf->flags & PF_FL_ZERO ? '0' : ' ', len);
		pf_add_chr_2_buff(pf, *str);
	}
}

void	pf_add_chr_2_buff(t_printf *pf, char chr)
{
	pf->buff[pf->buff_len++] = chr;
}

void	pf_parse_undefined(const char *format, t_printf *pf)
{
	if (format[pf->i] == '*' || format[pf->i] == '$')
	{
		while (format[pf->i])
			pf->i++;
		pf->buff_len = 0;
	}
}
