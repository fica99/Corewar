/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_exec_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:35:20 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/23 11:30:39 by olegmulko        ###   ########.fr       */
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
	bin_data->add(bin_data, prms->exec_code_size, 8);
	prms->exec_code_size = 0;
	return (asm_pars_opers(token, bin_data, prms));
}
