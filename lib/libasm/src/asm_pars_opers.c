/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_opers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:12:00 by ggrimes           #+#    #+#             */
/*   Updated: 2020/11/03 23:05:27 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		asm_pars_opers(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	while (1)
	{
		if (asm_skip_token(token, TT_SEP)
			|| asm_skip_token(token, TT_NEWLINE))
			continue ;
		else if ((*token)->type == TT_OPER)
		{
			if (asm_pars_oper(token, bin_data, prms) == -1)
				return (-1);
		}
		else if ((*token)->type == TT_EOF)
			break ;
		else
			return (asm_parser_error(*token, prms, ASM_ERR_MIS_OPER));
	}
	return (1);
}

int		asm_pars_oper(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	t_asm_oper		*oper;

	oper = (t_asm_oper *)(*token)->data;
	bin_data->add(bin_data, (int)oper->code, 2);
	prms->exec_code_size += 1;
	prms->args_mask = oper->args_mask;
	prms->dir_size = oper->dir_size;
	prms->mask_offset = 0;
	prms->oper_byte_index = prms->exec_code_size;
	asm_pars_type_args(*token, bin_data, prms);
	(*token) = (*token)->next;
	return (asm_pars_arg(token, bin_data, prms, 1));
}

static int asm_check_args_errors(t_asm_token **token,
	t_asm_pars_prms *prms, char arg_index)
{
	while (asm_skip_token(token, TT_SEP))
			;
	if (arg_index % 2 == 0 && (*token)->type != TT_ARG_SEP)
		return (asm_parser_error(*token, prms, ASM_MIS_ARG_SEP));
	else if (arg_index < (ARGS_SIZE * 2)
		&& ((*token)->type == TT_ARG_REG
		|| (*token)->type == TT_ARG_DIR
		|| (*token)->type == TT_ARG_IND))
		return (asm_parser_error(*token, prms, ASM_ERR_INVALID_ARG));
	else if (!asm_check_nl(token, prms))
		return (asm_parser_error(*token, prms, ASM_ERR_MIS_NL));
	else
		return (1);
}

int		asm_pars_arg(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms, char arg_index)
{
	if (arg_index <= 0)
		return (asm_parser_error(*token, prms, ASM_ERR_FUNC_PRMS));
	while (asm_skip_token(token, TT_SEP))
		;
	if (arg_index % 2 == 0 && (*token)->type == TT_ARG_SEP)
		return (asm_pars_args_sep(token, bin_data, prms, arg_index));
	else if (asm_pars_is_reg(token, prms, arg_index))
		return (asm_pars_reg(token, bin_data, prms, arg_index));
	else if (asm_pars_is_dir(token, prms, arg_index))
		return (asm_pars_dir(token, bin_data, prms, arg_index));
	else if (asm_pars_is_ind(token, prms, arg_index))
		return (asm_pars_ind(token, bin_data, prms, arg_index));
	else
		return (asm_check_args_errors(token, prms, arg_index));
}

int		asm_pars_args_sep(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms, char arg_index)
{
	(*token) = (*token)->next;
	while (asm_skip_token(token, TT_SEP))
		;
	if ((*token)->type != TT_ARG_REG
		&& (*token)->type != TT_ARG_DIR
		&& (*token)->type != TT_ARG_IND)
		return (asm_parser_error(*token, prms, ASM_ERR_MIS_ARG));
	return (asm_pars_arg(token, bin_data, prms, ++arg_index));
}
