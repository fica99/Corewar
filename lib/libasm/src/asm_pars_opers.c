/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_opers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:12:00 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/22 21:19:43 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		asm_direct_code_additional(int code)
{
	code = ~code;
	code += 1;
	return (code);
}

int		asm_pars_opers(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	static t_asm_labels	*labels;

	if (labels == NULL)
		labels = asm_init_labels(LABELS_SIZE);
	prms->labels = labels;
	while (1)
	{
		if (asm_skip_token(token, TT_SEP)
			|| asm_skip_token(token, TT_NEWLINE))
			continue ;
		else if ((*token)->type == TT_LABEL)
			return (asm_pars_label(token, bin_data, prms));
		else if ((*token)->type == TT_OPER)
			return (asm_pars_oper(token, bin_data, prms));
		else if ((*token)->type == TT_EOF)
			break ;
		else
			return (asm_parser_error(*token, (*token)->type, prms, 0));
	}
	return (1);
}

int		asm_pars_oper(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	t_asm_oper		*oper;
	t_asm_labels	*labels;

	oper = (t_asm_oper *)(*token)->data;
	bin_data->add(bin_data, (int)oper->code, 2);
	prms->exec_code_size += 1;
	labels = prms->labels;
	labels->inc(labels, 1);
	prms->args_mask = oper->args_mask;
	prms->mask_offset = 0;
	(*token) = (*token)->next;
	return (asm_pars_arg(token, bin_data, prms, 1));
}

int		asm_pars_arg(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms, char arg_index)
{
	if (arg_index <= 0)
		return (asm_parser_error(*token, (*token)->type, prms, 0));
	while (asm_skip_token(token, TT_SEP))
		;
	if (arg_index % 2 == 0 && (*token)->type == TT_ARG_SEP)
		asm_pars_args_sep(token);
	else if (asm_pars_is_reg(token, prms, arg_index))
		return (asm_pars_reg(token, bin_data, prms, arg_index));
	else if (asm_pars_is_dir(token, prms, arg_index))
		return (asm_pars_dir(token, bin_data, prms));
	else if (asm_pars_is_ind(token, prms, arg_index))
		return (asm_pars_ind(token, bin_data, prms));
	else
	{
		while (asm_skip_token(token, TT_SEP))
		;
		if (!asm_check_nl(token, prms))
			return (asm_parser_error(*token, TT_NEWLINE, prms, 0));
		return (1);
	}
	return (asm_pars_arg(token, bin_data, prms, ++arg_index));
}

void	asm_pars_args_sep(t_asm_token **token)
{
	(*token) = (*token)->next;
}
