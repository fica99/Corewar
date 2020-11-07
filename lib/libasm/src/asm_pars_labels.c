/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_labels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:30:18 by olegmulko         #+#    #+#             */
/*   Updated: 2020/11/07 14:54:38 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	asm_pars_labels_skip(t_asm_token **token,
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

int			asm_pars_label(t_asm_token **token,
	t_asm_pars_prms *prms)
{
	t_asm_labels	*labels;
	t_asm_token		*head;
	t_asm_token		*previous;

	labels = prms->labels;
	head = (*token);
	previous = head;
	while ((*token)->type != TT_EOF)
	{
		if (asm_pars_labels_skip(token, &previous))
			continue ;
		else if ((*token)->type == TT_LABEL)
		{
			if (asm_pars_check_label(token, prms, labels) == -1)
				return (-1);
			asm_pars_del_lebel(token, head, previous);
		}
		else if (asm_is_oper_or_args(*token))
			asm_pars_check_oper_and_args(token, prms, &previous);
		else
			asm_pars_check_size(token, prms, &previous, 0);
	}
	(*token) = head;
	return (1);
}
