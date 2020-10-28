/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:31:39 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 21:56:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*pf_pre_o(t_printf *pf, t_len_opts *len_opts)
{
	char		is_prec;

	is_prec = (pf->flags & PF_FL_ZERO) && pf->prec == -1;
	if (len_opts->sign && is_prec)
		pf->buff[pf->buff_len++] = len_opts->sign;
	if (pf->flags & PF_FL_HASH && is_prec)
		pf->buff[pf->buff_len++] = '0';
	if (!(pf->flags & PF_FL_MINUS))
		pf_align_to_width(pf, is_prec ? '0' : ' ', len_opts);
	if (len_opts->sign && !is_prec)
		pf->buff[pf->buff_len++] = len_opts->sign;
	if (pf->flags & PF_FL_HASH && !is_prec)
		pf->buff[pf->buff_len++] = '0';
	pf_align_to_accuracy(pf, '0', len_opts);
	return (len_opts);
}

static void	pf_check_hash_lo(t_printf *pf, t_len_opts *len_opts,
	intmax_t nb)
{
	(void)nb;
	if (pf->flags & PF_FL_HASH)
	{
		if (len_opts->w_len >= len_opts->num_len)
		{
			if (pf->width > len_opts->num_len && pf->prec == -1 && nb)
			{
				len_opts->ac_len++;
				len_opts->num_len++;
			}
			else if (pf->prec != -1
				&& (size_t)pf->prec > len_opts->num_len && nb)
				len_opts->num_len++;
			else if (pf->prec != -1 && ((size_t)pf->prec < len_opts->num_len
				|| (!pf->prec && !nb)))
			{
				len_opts->ac_len++;
				len_opts->num_len++;
			}
		}
	}
}

void		pf_handle_o(t_printf *pf, intmax_t nb, char *str)
{
	t_len_opts	*len_opts;
	char		print_num;

	len_opts = pf_init_len_opts(pf, nb, str);
	pf_check_hash_lo(pf, len_opts, nb);
	pf_check_mem(pf, pf->width + len_opts->w_len + 1);
	pf_pre_o(pf, len_opts);
	print_num = (!nb && (!pf->prec || pf->flags & PF_FL_HASH)) ? 0 : 1;
	if (print_num)
		pf_add_str_2_buff(pf, str, len_opts->nstr_len);
	if (pf->flags & PF_FL_MINUS)
		pf_align_to_width(pf, ' ', len_opts);
	ft_strdel(&str);
	ft_memdel((void**)&len_opts);
}
