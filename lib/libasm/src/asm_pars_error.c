/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:18:48 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/11 15:54:23 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		asm_parser_error(t_asm_token *token, t_asm_tkn_type type,
	t_asm_pars_prms *prms, size_t num_error)
{
	if (type == TT_CHAMP_NAME && num_error == 1)
		asm_fill_prms_from_token(token, prms, ERR_REP_CHAMP_NAME);
	else if (type == TT_CHAMP_NAME && num_error == 2)
		asm_fill_prms_from_token(token, prms, ERR_CHAMP_NAME_LEN);
	else if (type == TT_CHAMP_COMMENT && num_error == 1)
		asm_fill_prms_from_token(token, prms, ERR_REP_CHAMP_COMMENT);
	else if (type == TT_CHAMP_COMMENT && num_error == 2)
		asm_fill_prms_from_token(token, prms, ERR_CHAMP_COMMENT_LEN);
	else if (type == TT_NEWLINE)
		asm_fill_prms_from_token(token, prms, ERR_NL);
	else
		asm_fill_prms_from_token(token, prms, ERR_PARSER);
	return (-1);
}
