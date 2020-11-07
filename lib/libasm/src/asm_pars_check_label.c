/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_check_label.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:19:04 by ggrimes           #+#    #+#             */
/*   Updated: 2020/11/07 14:55:35 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		asm_pars_check_label(t_asm_token **token,
	t_asm_pars_prms *prms, t_asm_labels *labels)
{
	char		*label;

	label = (char *)(*token)->data;
	if (!(labels->add(labels, label, prms->exec_code_size + 1)))
		return (asm_parser_error(*token, prms, ASM_ERR_DUBL_LABEL));
	return (1);
}

void	asm_pars_del_lebel(t_asm_token **token,
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
