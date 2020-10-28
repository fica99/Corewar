/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token_arg_reg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:57:39 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 22:33:56 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_lex_is_number(t_asm_string *asm_str, size_t i)
{
	int			n_width;

	if (!(asm_str->str[i] == '-' || ft_isdigit(asm_str->str[i++])))
		return (0);
	n_width = 1;
	if (asm_str->str[i++] == '-')
		n_width++;
	while (ft_isdigit(asm_str->str[i++]))
		n_width++;
	return (n_width);
}

int				asm_lex_is_arg_reg(t_asm_string *asm_str)
{
	size_t		i;

	i = asm_str->index;
	if (asm_str->str[i++] != 'r')
		return (0);
	while (ft_isdigit(asm_str->str[i]))
		i++;
	return (1);
}

size_t			*asm_lex_get_number(t_asm_string *asm_str)
{
	size_t		*number;
	int			n_width;

	n_width = asm_lex_is_number(asm_str, asm_str->index);
	if (!(number = (size_t *)malloc(sizeof(size_t))))
		asm_sys_error();
	*number = (size_t)ft_atoi(asm_str->str + asm_str->index);
	asm_str->index += (size_t)n_width;
	asm_str->char_num += (size_t)n_width;
	return (number);
}

t_asm_token		*asm_lex_token_arg_reg(t_asm_string *asm_str)
{
	t_asm_token	*token;

	asm_str->index++;
	asm_str->char_num++;
	token = asm_lex_new_token(TT_ARG_REG);
	token->data = (void*)asm_lex_get_number(asm_str);
	return (token);
}
