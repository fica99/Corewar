/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_type_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:07:36 by olegmulko         #+#    #+#             */
/*   Updated: 2020/11/07 15:08:49 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static t_asm_token	*asm_write_type(t_asm_token *token,
	int *byte, int type, int *offset)
{
	(*byte) |= type >> (*offset);
	(*offset) += 2;
	return (token->next);
}

void				asm_pars_type_args(t_asm_token *token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	int		offset;
	int		byte;

	if ((prms->args_mask & ARG_TYPE) == 0)
		return ;
	offset = 0;
	byte = 0;
	while (1)
	{
		if (token->type == TT_ARG_REG)
			token = asm_write_type(token, &byte, ARG_TYPE_REG, &offset);
		else if (token->type == TT_ARG_DIR)
			token = asm_write_type(token, &byte, ARG_TYPE_DIR, &offset);
		else if (token->type == TT_ARG_IND)
			token = asm_write_type(token, &byte, ARG_TYPE_IND, &offset);
		else if (offset >= (ARGS_SIZE * 2)
			|| token->type == TT_NEWLINE
			|| token->type == TT_EOF)
			break ;
		else
			token = token->next;
	}
	bin_data->add(bin_data, byte, 2);
	prms->exec_code_size++;
}
