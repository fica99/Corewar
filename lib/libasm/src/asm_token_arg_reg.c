/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_arg_reg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:33:34 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/29 20:58:17 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_is_number(t_asm_string *asm_str, size_t i)
{
	int			n_width;

	if (!ft_isdigit(asm_str->str[i++]))
		return (0);
	n_width = 1;
	while (ft_isdigit(asm_str->str[i++]))
		n_width++;
	return (n_width);
}

int				asm_check_arg_reg(t_asm_string *asm_str)
{
	size_t		i;

	i = asm_str->index;
	if (asm_str->str[i++] != 'r')
		return (0);
	while (ft_isdigit(asm_str->str[i]))
		i++;
	return (1);
}

size_t			*asm_get_number(t_asm_string *asm_str)
{
	size_t		*number;
	int			n_width;

	n_width = asm_is_number(asm_str, asm_str->index);
	if (!(number = (size_t *)malloc(sizeof(size_t))))
		asm_sys_error();
	*number = (size_t)ft_atoi(asm_str->str + asm_str->index);
	asm_str->index += (size_t)n_width;
	asm_str->char_num += (size_t)n_width;
	return (number);
}

t_asm_token		*asm_token_arg_reg(t_asm_string *asm_str)
{
	t_asm_token	*token;

	asm_str->index++;
	asm_str->char_num++;
	token = asm_lex_new_token(TT_ARG_REG);
	token->data = (void*)asm_get_number(asm_str);
	return (token);
}
