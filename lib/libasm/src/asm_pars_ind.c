/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_ind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:16:50 by olegmulko         #+#    #+#             */
/*   Updated: 2020/11/07 14:12:14 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int			asm_pars_is_ind(t_asm_token **token,
	t_asm_pars_prms *prms, char arg_index)
{
	if (arg_index % 2 != 0
		&& arg_index < ARGS_SIZE * 2
		&& ((prms->args_mask >> prms->mask_offset) & ARG_1_IND)
		&& (*token)->type == TT_ARG_IND)
	{
		prms->mask_offset += 3;
		return (1);
	}
	return (0);
}

static int	asm_pars_ind_int(t_asm_token **token, t_asm_bin_data *bin_data,
	t_asm_pars_prms *prms, char arg_index)
{
	int				*data;

	data = (int *)(*token)->data;
	bin_data->add(bin_data, *data, 2 * IND_SIZE);
	prms->exec_code_size += IND_SIZE;
	(*token) = (*token)->next;
	return (asm_pars_arg(token, bin_data, prms, ++arg_index));
}

static int	asm_pars_ind_str(t_asm_token **token, t_asm_bin_data *bin_data,
	t_asm_pars_prms *prms, char arg_index)
{
	char			*data;
	t_asm_labels	*labels;
	int				lebel_index;

	data = (char *)(*token)->data;
	labels = prms->labels;
	if ((lebel_index = labels->is_contain(labels, data)) == -1)
		return (asm_parser_error(*token, prms, ASM_ERR_LABEL));
	lebel_index = lebel_index - prms->oper_byte_index;
	bin_data->add(bin_data, lebel_index, 2 * IND_SIZE);
	prms->exec_code_size += IND_SIZE;
	(*token) = (*token)->next;
	return (asm_pars_arg(token, bin_data, prms, ++arg_index));
}

int			asm_pars_ind(t_asm_token **token, t_asm_bin_data *bin_data,
	t_asm_pars_prms *prms, char arg_index)
{
	if ((*token)->type_conv == TC_SIZE_T)
		return (asm_pars_ind_int(token, bin_data, prms, arg_index));
	else if ((*token)->type_conv == TC_STR)
		return (asm_pars_ind_str(token, bin_data, prms, arg_index));
	else
		return (asm_parser_error(*token, prms, ASM_ERR_CAST_TYPE));
}
