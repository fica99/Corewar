/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_ch_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 20:35:03 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/11 13:13:05 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	asm_add_chn_to_bd(t_asm_bin_data *bin_data,
	char *name)
{
	size_t	i;

	i = 0;
	bin_data->index = 4;
	bin_data->part = 1;
	while (name[i])
		bin_data->add(bin_data, (int)name[i++], 2);
	while (i < PROG_NAME_LENGTH)
	{
		bin_data->add(bin_data, 0, 2);
		i++;
	}
}

int			asm_pars_champ_name(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	char		*name;
	size_t		size;

	(void)prms;
	(*token) = (*token)->next;
	while (asm_skip_token(token, TT_SEP))
		;
	if ((*token)->type != TT_STRING)
		return (0);
	name = (char *)(*token)->data;
	if ((size = ft_strlen(name)) > PROG_NAME_LENGTH)
		return (0);
	asm_add_chn_to_bd(bin_data, name);
	asm_add_null_in_bd(bin_data, 4);
	(*token) = (*token)->next;
	while (asm_skip_token(token, TT_SEP))
		;
	if (!asm_check_nl(token, prms))
		return (0);
	return (1);
}
