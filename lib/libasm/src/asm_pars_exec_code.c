/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_exec_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:35:20 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/08 19:54:32 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	asm_exec_code(t_asm_token *token,
	t_asm_bin_data *bin_data)
{
	bin_data->add(bin_data, 0, 8);
	asm_pars_champ_comment(token, bin_data);
}
