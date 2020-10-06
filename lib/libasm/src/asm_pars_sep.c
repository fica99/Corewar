/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_sep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 23:11:52 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/06 23:22:01 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	asm_check_sep(t_asm_token **token)
{
	while ((*token)->type == TT_SEP)
		*token = (*token)->next;
}

void	asm_check_nl(t_asm_token **token)
{
	if ((*token)->type != TT_NEWLINE)
		asm_prog_error("missing line break");
	*token = (*token)->next;
}
