/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_sep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 23:11:52 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/10 21:23:10 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	asm_check_nl(t_asm_token **token,
	t_asm_pars_prms *prms)
{
	(void)prms;
	if ((*token)->type != TT_NEWLINE)
		return (0);
	(*token) = (*token)->next;
	return (1);
}
