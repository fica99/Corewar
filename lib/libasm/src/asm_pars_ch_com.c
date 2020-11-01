/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_ch_com.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:03:06 by ggrimes           #+#    #+#             */
/*   Updated: 2020/11/01 20:20:52 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	asm_add_chc_to_bd(t_asm_bin_data *bin_data,
	char *name)
{
	size_t	i;

	i = 0;
	bin_data->index = 4 + PROG_NAME_LENGTH + 8;
	bin_data->part = 1;
	while (name[i])
		bin_data->add(bin_data, (int)name[i++], 2);
	while (i < COMMENT_LENGTH)
	{
		bin_data->add(bin_data, 0, 2);
		i++;
	}
}

int			asm_pars_champ_comment(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	char	*comment;
	size_t	size;

	(void)prms;
	(*token) = (*token)->next;
	while (asm_skip_token(token, TT_SEP))
		;
	if ((*token)->type != TT_STRING)
		return (asm_parser_error(*token, 0, prms, 0));
	comment = (char *)(*token)->data;
	if ((size = ft_strlen(comment)) > COMMENT_LENGTH)
		return (asm_parser_error(*token, TT_CHAMP_COMMENT, prms, 2));
	asm_add_chc_to_bd(bin_data, comment);
	asm_add_null_in_bd(bin_data, 4);
	(*token) = (*token)->next;
	while (asm_skip_token(token, TT_SEP))
		;
	if (!asm_check_nl(token, prms))
		return (asm_parser_error(*token, TT_NEWLINE, prms, 0));
	return (1);
}
