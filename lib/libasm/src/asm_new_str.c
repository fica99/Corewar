/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_new_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:26:29 by olegmulko         #+#    #+#             */
/*   Updated: 2020/11/07 13:26:58 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_string		*asm_new_str(size_t m_size)
{
	t_asm_string	*new_string;
	char			*str;

	if (!(new_string = (t_asm_string*)malloc(sizeof(t_asm_string))))
		asm_sys_error();
	if (!(str = (char *)malloc(sizeof(char) * (m_size))))
		asm_sys_error();
	*str = '\0';
	new_string->str = str;
	new_string->m_size = m_size;
	new_string->size = 0;
	new_string->line_num = 1;
	new_string->char_num = 1;
	new_string->index = 0;
	return (new_string);
}
