/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:15:14 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/08 20:18:28 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	asm_parser(t_asm_token *token,
	t_asm_bin_data *bin_data)
{
	while (token->type == TT_COMMENT)
		token = token->next;
	asm_pars_champ_name(token->next, bin_data);
}
