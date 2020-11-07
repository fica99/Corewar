/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:08:44 by ggrimes           #+#    #+#             */
/*   Updated: 2020/11/07 16:07:41 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static size_t	asm_get_filename_len(size_t name_len, size_t exp_len)
{
	size_t		len;

	len = name_len;
	if (exp_len)
		len += exp_len + 1;
	return (len);
}

static void	asm_open_file(t_asm_file *file, int mod, int adv_mod)
{
	size_t	name_len;
	size_t	exp_len;
	size_t	len;
	char	*full_path;
	int		fd;

	name_len = ft_strlen(file->name);
	exp_len = ft_strlen(file->exp);
	len = asm_get_filename_len(name_len, exp_len);
	if (!(full_path = ft_strnew(len)))
		asm_sys_error();
	ft_memcpy(full_path, file->name, name_len);
	if (exp_len)
	{
		ft_memcpy(full_path + name_len, ".", 1);
		ft_memcpy(full_path + name_len + 1, file->exp, exp_len);
	}
	fd = open(full_path, mod, adv_mod);
	if (fd == -1)
		asm_sys_error();
	free(full_path);
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

t_asm_file	*asm_file_init(char *name, char *exp)
{
	t_asm_file	*file;

	if (!(file = (t_asm_file *)malloc(sizeof(t_asm_file))))
		asm_sys_error();
	if (name == NULL)
		asm_prog_error(ERR_FILE_NAME_NULL);
	if (!(file->name = asm_del_exp(name)))
		asm_sys_error();
	if (!(file->exp = ft_strdup(exp)))
		asm_sys_error();
	file->open = &asm_open_file;
	file->write_bin_data = &asm_write_bin_data_to_file;
	return (file);
}

char		*asm_del_exp(char *filename)
{
	char	*name;
	char	*sep;
	char	tmp_ch;

	if (!filename)
		return (NULL);
	tmp_ch = '\0';
	sep = ft_strrchr(filename, '.');
	if (sep)
	{
		tmp_ch = *sep;
		*sep = '\0';
	}
	if (!(name = ft_strdup(filename)))
		asm_sys_error();
	if (tmp_ch)
		*sep = tmp_ch;
	return (name);
}
