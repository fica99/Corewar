/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:18:48 by ggrimes           #+#    #+#             */
/*   Updated: 2020/11/03 23:06:16 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	asm_parser_error_next(t_asm_token *token,
	t_asm_pars_prms *prms, t_asm_errors error)
{
	if (error == ASM_ERR_MIS_NL)
		asm_fill_prms_from_token(token, prms, ERR_MIS_NL);
	else if (error == ASM_ERR_REG_SIZE)
		asm_fill_prms_from_token(token, prms, ERR_REG_SIZE);
	else if (error == ASM_ERR_LABEL)
		asm_fill_prms_from_token(token, prms, ERR_LABEL);
	else if (error == ASM_ERR_CAST_TYPE)
		asm_fill_prms_from_token(token, prms, ERR_CAST_TYPE);
	else
		asm_fill_prms_from_token(token, prms, ERR_PARSER);
	return (-1);
}

int			asm_parser_error(t_asm_token *token,
	t_asm_pars_prms *prms, t_asm_errors error)
{
	if (error == ASM_ERR_CHAMP_NAME)
		asm_fill_prms_from_token(token, prms, ERR_CHAMP_NAME);
	else if (error == ASM_ERR_MIS_STR)
		asm_fill_prms_from_token(token, prms, ERR_MIS_STR);
	else if (error == ASM_ERR_CHAMP_NAME_LEN)
		asm_fill_prms_from_token(token, prms, ERR_CHAMP_NAME_LEN);
	else if (error == ASM_ERR_CHAMP_COMMENT)
		asm_fill_prms_from_token(token, prms, ERR_CHAMP_COMMENT);
	else if (error == ASM_ERR_CHAMP_COMMENT_LEN)
		asm_fill_prms_from_token(token, prms, ERR_CHAMP_COMMENT_LEN);
	else if (error == ASM_ERR_FUNC_PRMS)
		asm_fill_prms_from_token(token, prms, ERR_FUNC_PRMS);
	else if (error == ASM_ERR_MIS_OPER)
		asm_fill_prms_from_token(token, prms, ERR_MIS_OPER);
	else if (error == ASM_MIS_ARG_SEP)
		asm_fill_prms_from_token(token, prms, ERR_MIS_ARG_SEP);
	else if (error == ASM_ERR_NOT_ARG)
		asm_fill_prms_from_token(token, prms, ERR_NOT_ARG);
	else if (error == ASM_ERR_INVALID_ARG)
		asm_fill_prms_from_token(token, prms, ERR_INVALID_ARG);
	else if (error == ASM_ERR_MIS_ARG)
		asm_fill_prms_from_token(token, prms, ERR_MIS_ARG);
	else
		return (asm_parser_error_next(token, prms, error));
	return (-1);
}
