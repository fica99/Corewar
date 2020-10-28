/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_len_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:21:30 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/28 21:56:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_len_opts	*pf_init_len_opts(t_printf *pf, intmax_t nb, char *str)
{
	t_len_opts	*len_opts;

	if (!(len_opts = (t_len_opts*)malloc(sizeof(t_len_opts))))
		exit(1);
	len_opts->sign = pf_check_sign(pf, nb);
	len_opts->num_len = pf_get_num_len(nb, str, len_opts->sign, pf->prec);
	len_opts->w_len = pf_get_w_len(pf, len_opts->num_len);
	len_opts->ac_len = pf_get_ac_len(pf, nb, len_opts);
	len_opts->nstr_len = ft_strlen(str);
	return (len_opts);
}

size_t		pf_get_num_len(intmax_t nb, char *str, char sign, int prec)
{
	size_t	num_len;

	if (!prec && !nb)
		return (0);
	num_len = ft_strlen(str);
	if (sign)
		num_len++;
	return (num_len);
}

size_t		pf_get_w_len(t_printf *pf, size_t num_len)
{
	if (pf->width > num_len)
		return (pf->width);
	return (num_len);
}

size_t		pf_get_ac_len(t_printf *pf, intmax_t nb,
	t_len_opts *len_opts)
{
	if (!pf->prec && !nb)
		return ((size_t)pf->prec);
	else if ((int)len_opts->num_len < pf->prec)
	{
		if (len_opts->sign)
			return ((size_t)pf->prec + 1);
		return ((size_t)pf->prec);
	}
	else
		return (len_opts->num_len);
}
