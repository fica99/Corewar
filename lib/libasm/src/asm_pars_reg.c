/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:46:40 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 21:40:58 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		asm_pars_is_reg(t_asm_token **token,
	t_asm_pars_prms *prms, char arg_index)
{
	if (arg_index % 2 != 0
		&& ((prms->args_mask >> prms->mask_offset) & ARG_1_REG)
		&& (*token)->type == TT_ARG_REG)
	{
		prms->mask_offset++;
		return (1);
	}
	return (0);
}

int		asm_pars_reg(t_asm_token **token, t_asm_bin_data *bin_data,
	t_asm_pars_prms *prms, char arg_index)
{
	int	*data;

	data = (int *)(*token)->data;
	if ((*data) > REG_NUMBER)
		return (asm_parser_error(*token, (*token)->type, prms, 0));
	bin_data->add(bin_data, *data, 2 * REG_SIZE);
	prms->exec_code_size += REG_SIZE;
	(*token) = (*token)->next;
	return (asm_pars_arg(token, bin_data, prms, ++arg_index));
}
