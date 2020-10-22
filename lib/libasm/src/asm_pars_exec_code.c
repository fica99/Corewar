/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_exec_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:35:20 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/11 19:23:48 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	asm_exec_code(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	size_t	index;

	index = 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH;
	bin_data->index = index;
	if (asm_pars_opers(token, bin_data, prms) == -1)
		return (asm_parser_error(*token, (*token)->type, prms, 0));
	bin_data->index = 4 + PROG_NAME_LENGTH + 4;
	bin_data->part = 1;
	bin_data->add(bin_data, prms->exec_code_size, 8);
	bin_data->index = index;
	return (1);
}
