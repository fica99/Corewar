/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:52:51 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/21 22:55:37 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		asm_pars_is_dir(t_asm_token **token,
	t_asm_pars_prms *prms, char arg_index)
{
	if (arg_index % 2 != 0
		&& ((prms->args_mask >> prms->mask_offset++) & ARG_1_DIR)
		&& (*token)->type == TT_ARG_DIR)
		return (1);
	return (0);
}

int		asm_pars_dir(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	(void)bin_data;
	(void)prms;
	(*token) = (*token)->next;
	return (1);
}
