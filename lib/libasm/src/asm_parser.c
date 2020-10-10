/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:15:14 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/10 18:48:40 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_pars_prms	*asm_init_pars_prms(t_asm_token *token,
	t_asm_bin_data *bin_data)
{
	t_asm_pars_prms	*prms;

	if (!(prms = (t_asm_pars_prms *)malloc(
		sizeof(t_asm_pars_prms))))
		asm_sys_error();
	prms->token = (token) ? token : NULL;
	prms->bin_data = (bin_data) ? bin_data : NULL;
	prms->exec_code_size = 0;
	return (prms);
}

void			asm_parser(t_asm_pars_prms *prms)
{
	prms->bin_data->add(prms->bin_data, COREWAR_EXEC_MAGIC, 8);
}
