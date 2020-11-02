/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_labels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:30:18 by olegmulko         #+#    #+#             */
/*   Updated: 2020/11/03 19:40:07 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	asm_pars_check_label(t_asm_token **token,
	t_asm_pars_prms *prms, t_asm_labels *labels)
{
	char		*label;

	label = (char *)(*token)->data;
	if (labels->add(labels, label, prms->exec_code_size + 1) == -1)
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
	t_asm_pars_prms *prms, t_asm_token **previous, int size)
{
	(void)previous;
	prms->exec_code_size += size;
	(*previous) = (*token);
	(*token) = (*token)->next;
}

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

static int 	asm_pars_labels_skip(t_asm_token **token,
	t_asm_token **previous)
{
	(void)previous;

	if ((*token)->type == TT_SEP
		|| (*token)->type == TT_NEWLINE
		|| (*token)->type == TT_ARG_SEP)
	{
		(*previous) = (*token);
		(*token) = (*token)->next;
		return (1);
	}
	return (0);
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
		if (asm_pars_labels_skip(token, &previous))
			continue ;
		else if ((*token)->type == TT_LABEL)
			asm_pars_check_label(token, prms, labels);
		else if ((*token)->type == TT_OPER)
			asm_pars_check_oper(token, prms, &previous);
		else if ((*token)->type == TT_ARG_REG)
			asm_pars_check_size(token, prms, &previous, 1);
		else if ((*token)->type == TT_ARG_DIR)
			asm_pars_check_dir(token, prms, &previous);
		else if ((*token)->type == TT_ARG_IND)
			asm_pars_check_size(token, prms, &previous, IND_SIZE);
		else if ((*token)->type == TT_EOF)
			break ;
		else
			asm_pars_check_size(token, prms, &previous, 0);
		if ((*token)->type == TT_LABEL)
			asm_pars_del_lebel(token, head, previous);
	}
	(*token) = head;
}
