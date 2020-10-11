/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_exec_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:35:20 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/11 13:30:01 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	asm_exec_code(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	(void)prms;
	(void)token;
	bin_data->index = 4 + PROG_NAME_LENGTH + 4;
	bin_data->part = 1;
	bin_data->add(bin_data, 22, 8);
	bin_data->index += COMMENT_LENGTH;
	return (1);
}
