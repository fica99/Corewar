/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_opers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:12:00 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/20 21:10:45 by ggrimes          ###   ########.fr       */
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
	while (1)
	{
		if (asm_skip_token(token, TT_SEP)
			|| asm_skip_token(token, TT_NEWLINE))
			continue ;
		else if ((*token)->type == TT_LABEL)
			return (asm_pars_label(token, bin_data, prms));
		else if ((*token)->type == TT_OPER)
			return (-1);
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
	t_asm_oper	*oper;
	char		*oper_name;

	oper_name = (char *)(*token)->data;
	oper = (t_asm_oper *)get_hash_data(prms->opers_hash, oper_name, OPERS_SIZE);
	bin_data->add(bin_data, (int)oper->code, 2);
	prms->exec_code_size += 1;
	prms->args_mask = oper->args_mask;
	prms->args_size = 3;
	(*token) = (*token)->next;
	return (asm_pars_arg(token, bin_data, prms, 1));
}

int		asm_pars_arg(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms, char arg_index)
{
	(void)bin_data;
	char	offset;

	if (arg_index <= 0)
		return (asm_parser_error(*token, (*token)->type, prms, 0));
	while (asm_skip_token(token, TT_SEP))
		;
	offset = arg_index - 1;
	if ((prms->args_mask >> offset) & ARG_1_REG)
		asm_pars_reg(token, bin_data, prms);
	else if (((prms->args_mask >> offset) & ARG_1_DIR))
		asm_pars_dir(token, bin_data, prms);
	else if (((prms->args_mask >> offset) & ARF_1_IND))
		asm_pars_ind(token, bin_data, prms);
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

void	asm_pars_reg(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	(void)bin_data;
	(void)prms;
	while (asm_skip_token(token, TT_SEP))
		;
	(*token) = (*token)->next;
	return ;
}

void	asm_pars_dir(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	(void)bin_data;
	(void)prms;
	while (asm_skip_token(token, TT_SEP))
		;
	(*token) = (*token)->next;
	return ;
}

void	asm_pars_ind(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	(void)bin_data;
	(void)prms;
	while (asm_skip_token(token, TT_SEP))
		;
	(*token) = (*token)->next;
	return ;
}
