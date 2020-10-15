/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_labels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:30:18 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/15 20:09:15 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		asm_pars_label(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	(void)bin_data;
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
			labels->add(labels, (char *)(*token)->data);
		else
			break ;
	}
	labels->clear(labels);
	return (1);
}
