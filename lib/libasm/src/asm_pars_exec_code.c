/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_exec_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:35:20 by olegmulko         #+#    #+#             */
/*   Updated: 2020/11/01 20:16:00 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	asm_exec_code(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	static t_asm_labels	*labels;

	if (labels == NULL)
		labels = asm_init_labels(LABELS_SIZE);
	prms->labels = labels;
	asm_pars_label(token, prms);
	bin_data->index = 4 + PROG_NAME_LENGTH + 4;
	bin_data->add(bin_data, prms->exec_code_size, 8);
	prms->exec_code_size = 0;
	bin_data->index = 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4;
	return (asm_pars_opers(token, bin_data, prms));
}
