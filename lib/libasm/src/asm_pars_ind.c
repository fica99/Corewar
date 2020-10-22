/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_ind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:16:50 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/22 21:17:48 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		asm_pars_is_ind(t_asm_token **token,
	t_asm_pars_prms *prms, char arg_index)
{
	if (arg_index % 2 != 0
		&& ((prms->args_mask >> prms->mask_offset++) & ARF_1_IND)
		&& (*token)->type == TT_ARG_IND)
		return (1);
	return (0);
}

int		asm_pars_ind(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	(void)bin_data;
	(void)prms;
	(*token) = (*token)->next;
	return (1);
}
