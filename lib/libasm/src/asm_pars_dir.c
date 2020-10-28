/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:52:51 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 21:40:26 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int			asm_pars_is_dir(t_asm_token **token,
	t_asm_pars_prms *prms, char arg_index)
{
	if (arg_index % 2 != 0
		&& ((prms->args_mask >> prms->mask_offset) & ARG_1_DIR)
		&& (*token)->type == TT_ARG_DIR)
	{
		prms->mask_offset++;
		return (1);
	}
	return (0);
}

static int	asm_pars_dir_int(t_asm_token **token, t_asm_bin_data *bin_data,
	t_asm_pars_prms *prms, char arg_index)
{
	int				*data;

	data = (int *)(*token)->data;
	bin_data->add(bin_data, *data, 2 * DIR_SIZE);
	prms->exec_code_size += DIR_SIZE;
	(*token) = (*token)->next;
	return (asm_pars_arg(token, bin_data, prms, ++arg_index));
}

static int	asm_pars_dir_str(t_asm_token **token, t_asm_bin_data *bin_data,
	t_asm_pars_prms *prms, char arg_index)
{
	char			*data;
	t_asm_labels	*labels;
	int				num;

	data = (char *)(*token)->data;
	labels = prms->labels;
	if ((num = labels->is_contain(labels, data)) == -1)
		return (asm_parser_error(*token, (*token)->type, prms, 0));
	num = num - prms->exec_code_size;
	bin_data->add(bin_data, num, 2 * DIR_SIZE);
	prms->exec_code_size += DIR_SIZE;
	(*token) = (*token)->next;
	return (asm_pars_arg(token, bin_data, prms, ++arg_index));
}

int			asm_pars_dir(t_asm_token **token, t_asm_bin_data *bin_data,
	t_asm_pars_prms *prms, char arg_index)
{
	if ((*token)->type_conv == TC_SIZE_T)
		return (asm_pars_dir_int(token, bin_data, prms, arg_index));
	else if ((*token)->type_conv == TC_STR)
		return (asm_pars_dir_str(token, bin_data, prms, arg_index));
	else
		return (asm_parser_error(*token, (*token)->type, prms, 0));
}
