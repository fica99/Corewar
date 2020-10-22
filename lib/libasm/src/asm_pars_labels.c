/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_labels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:30:18 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/23 11:23:46 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	asm_pars_check_label(t_asm_token **token,
	t_asm_pars_prms *prms, t_asm_labels *labels)
{
	char		*label;

	label = (char *)(*token)->data;
	if (labels->add(labels, label, prms->exec_code_size) == -1)
		asm_sys_error();
}

static void	asm_pars_del_lebel(t_asm_token **token,
	t_asm_token *head, t_asm_token *previous)
{
	t_asm_token	*del;

	del = (*token);
	if (head == (*token))
	{
		(*token) = (*token)->next;
		head = (*token);
	}
	else
	{
		(*token) = (*token)->next;
		previous->next = (*token);
	}
	asm_lex_del_token(&del);
}

static void	asm_pars_check_size(t_asm_token **token,
	t_asm_pars_prms *prms, t_asm_token *previous, int size)
{
	(void)previous;
	prms->exec_code_size += size;
	previous = (*token);
	(*token) = (*token)->next;
}

void		asm_pars_label(t_asm_token **token,
	t_asm_pars_prms *prms)
{
	t_asm_labels	*labels;
	t_asm_token		*head;
	t_asm_token		*previous;

	labels = prms->labels;
	head = (*token);
	previous = head;
	while (1)
	{
		if (asm_skip_token(token, TT_SEP)
			|| asm_skip_token(token, TT_NEWLINE)
			|| asm_skip_token(token, TT_ARG_SEP))
			continue ;
		else if ((*token)->type == TT_LABEL)
			asm_pars_check_label(token, prms, labels);
		else if ((*token)->type == TT_OPER)
			asm_pars_check_size(token, prms, previous, 2);
		else if ((*token)->type == TT_ARG_REG)
			asm_pars_check_size(token, prms, previous, REG_SIZE);
		else if ((*token)->type == TT_ARG_DIR)
			asm_pars_check_size(token, prms, previous, DIR_SIZE);
		else if ((*token)->type == TT_ARG_IND)
			asm_pars_check_size(token, prms, previous, IND_SIZE);
		else if ((*token)->type == TT_EOF)
			break ;
		if ((*token)->type == TT_LABEL)
			asm_pars_del_lebel(token, head, previous);
	}
	(*token) = head;
}
