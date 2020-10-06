/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:15:14 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/06 22:53:52 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	asm_parser(t_asm_token *token,
	t_asm_bin_data *bin_data)
{
	while (token->type == TT_COMMENT)
		token = token->next;
	if (token->type == TT_CHAMP_NAME)
		asm_pars_champ_name(token->next, bin_data);
	else
		asm_prog_error("parser error");
}
