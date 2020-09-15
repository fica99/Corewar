/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_arg_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:32:26 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/15 21:38:57 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_check_arg_dir(t_asm_string *asm_str)
{
	size_t		i;

	i = asm_str->index;
	if (asm_str->str[i++] != DIRECT_CHAR)
		return (0);
	if (asm_str->str[i++] != LABEL_CHAR)
		return (0);
	while (ft_strchr(LABEL_CHARS, asm_str->str[i]))
		i++;
	if (asm_str->str[i] != SEPARATOR_CHAR
		&& asm_str->str[i] != ' '
		&& asm_str->str[i] != '\n')
		return (0);
	return (1);
}
