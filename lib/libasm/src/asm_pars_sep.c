/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_sep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 23:11:52 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/08 20:41:57 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		asm_check_sep(t_asm_token **token)
{
	int	check;

	check = 0;
	while ((*token)->type == TT_SEP)
	{
		check = 1;
		*token = (*token)->next;
	}
	return (check);
}

void	asm_check_nl(t_asm_token **token)
{
	if ((*token)->type != TT_NEWLINE)
		asm_prog_error("missing line break");
	while ((*token)->type == TT_NEWLINE)
		*token = (*token)->next;
}

int		asm_check_nl_in_loop(t_asm_token **token)
{
	int	check;

	check = 0;
	while ((*token)->type == TT_NEWLINE)
	{
		check = 1;
		*token = (*token)->next;
	}
	return (check);
}
