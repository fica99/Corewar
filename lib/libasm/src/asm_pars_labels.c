/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_labels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:30:18 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/22 22:11:07 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	asm_pars_add_label(t_asm_token **token,
	t_asm_labels *labels)
{
	labels->add(labels, (char *)(*token)->data);
	(*token) = (*token)->next;
}

int		asm_pars_label(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	t_asm_labels	*labels;

	labels = prms->labels;
	while (1)
	{
		if (asm_skip_token(token, TT_SEP)
			|| asm_skip_token(token, TT_NEWLINE))
			continue ;
		else if ((*token)->type == TT_LABEL)
			asm_pars_add_label(token, labels);
		else
			break ;
	}
	while (asm_skip_token(token, TT_SEP)
		|| asm_skip_token(token, TT_NEWLINE))
		;
	if ((*token)->type == TT_OPER)
		return (asm_pars_oper(token, bin_data, prms));
	return (1);
}
