/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:08:44 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/06 21:47:10 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	asm_open_file(t_asm_file *file, int mod, int adv_mod)
{
	int		fd;

	fd = open(file->name, mod, adv_mod);
	if (fd == -1)
		asm_sys_error();
	file->fd = fd;
}

static void	asm_write_bin_data_to_file(t_asm_file *file,
	t_asm_bin_data *bin_data)
{
	int		wb;

	wb = write(file->fd, bin_data->data, bin_data->size);
	if (wb == -1)
		asm_sys_error();
}

t_asm_file	*asm_file_init(char *name)
{
	t_asm_file	*file;

	if (!(file = (t_asm_file *)malloc(sizeof(t_asm_file))))
		asm_sys_error();
	if (name == NULL)
		asm_prog_error(ERR_FILE_NAME_NULL);
	file->name = name;
	file->open = &asm_open_file;
	file->write_bin_data = &asm_write_bin_data_to_file;
	return (file);
}
