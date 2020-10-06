/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:08:44 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/06 21:17:04 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_file	*asm_file_init(char *name)
{
	t_asm_file	*file;

	if (!(file = (t_asm_file *)malloc(sizeof(t_asm_file))))
		asm_sys_error();
	if (name == NULL)
		asm_prog_error(ERR_FILE_NAME_NULL);
	file->name = name;
	return (file);
}
