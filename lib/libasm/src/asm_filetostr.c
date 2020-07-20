/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_filetostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:34:50 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/20 16:03:35 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int			asm_get_fd(char *file_path)
{
	int			fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		asm_sys_error();
	return (fd);
}

static void			asm_copy_buf_to_str(t_asm_string *asm_str,
	char *buf, size_t rb)
{
	size_t		delta_size;
	char		*str_pos;

	delta_size = asm_str->m_size - asm_str->size;
	while (delta_size < rb)
	{
		asm_str_realoc(asm_str);
		delta_size = asm_str->m_size - asm_str->size;
	}
	str_pos = asm_str->str + asm_str->size;
	ft_memcpy(str_pos, buf, rb);
	asm_str->size += rb;
}

static t_asm_string	*asm_read_file(int fd, char *buf)
{
	t_asm_string	*asm_str;
	int				rb;

	asm_str = asm_new_str(STR_MALOC_SIZE);
	while ((rb = read(fd, buf, READ_BUF_SIZE)))
	{
		if (rb == -1)
			asm_sys_error();
		asm_copy_buf_to_str(asm_str, buf, (size_t)(rb));
	}
	return (asm_str);
}

t_asm_string		*asm_file_to_str(char *file_path)
{
	int				fd;
	char			*buf;
	t_asm_string	*asm_str;

	fd = asm_get_fd(file_path);
	if (!(buf = (char*)malloc(sizeof(char) * (READ_BUF_SIZE + 1))))
		asm_sys_error();
	buf[READ_BUF_SIZE] = '\0';
	asm_str = asm_read_file(fd, buf);
	ft_memdel((void**)&buf);
	close(fd);
	return (asm_str);
}
