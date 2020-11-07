/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_labels_oper_args.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:40:02 by ggrimes           #+#    #+#             */
/*   Updated: 2020/11/07 14:54:27 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	asm_pars_check_oper(t_asm_token **token,
	t_asm_pars_prms *prms, t_asm_token **previous)
{
	t_asm_oper	*oper;

	(void)previous;
	oper = (t_asm_oper *)(*token)->data;
	prms->exec_code_size++;
	prms->dir_size = oper->dir_size;
	if ((oper->args_mask & ARG_TYPE))
		prms->exec_code_size++;
	(*previous) = (*token);
	(*token) = (*token)->next;
}

static void	asm_pars_check_dir(t_asm_token **token,
	t_asm_pars_prms *prms, t_asm_token **previous)
{
	(void)previous;
	prms->exec_code_size += prms->dir_size;
	(*previous) = (*token);
	(*token) = (*token)->next;
}

void		asm_pars_check_size(t_asm_token **token,
	t_asm_pars_prms *prms, t_asm_token **previous, int size)
{
	(void)previous;
	prms->exec_code_size += size;
	(*previous) = (*token);
	(*token) = (*token)->next;
}

int			asm_is_oper_or_args(t_asm_token *token)
{
	if (token->type == TT_OPER
		|| token->type == TT_ARG_REG
		|| token->type == TT_ARG_DIR
		|| token->type == TT_ARG_IND)
		return (1);
	return (0);
}

void		asm_pars_check_oper_and_args(t_asm_token **token,
	t_asm_pars_prms *prms, t_asm_token **previous)
{
	if ((*token)->type == TT_OPER)
		asm_pars_check_oper(token, prms, previous);
	else if ((*token)->type == TT_ARG_REG)
		asm_pars_check_size(token, prms, previous, 1);
	else if ((*token)->type == TT_ARG_DIR)
		asm_pars_check_dir(token, prms, previous);
	else if ((*token)->type == TT_ARG_IND)
		asm_pars_check_size(token, prms, previous, IND_SIZE);
}
