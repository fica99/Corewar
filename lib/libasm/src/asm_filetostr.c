/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_filetostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:34:50 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/13 21:46:36 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int		asm_get_fd(char *file_path)
{
	int			fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		asm_sys_error();
	return (fd);
}

static void		asm_copy_buf_to_str(t_string *s_str, char *buf, size_t rb)
{
	size_t		delta_size;
	char		*str_pos;

	delta_size = s_str->m_size - s_str->size;
	while (delta_size < rb)
	{
		if (!ft_strs_realoc(s_str))
			asm_sys_error();
		delta_size = s_str->m_size - s_str->size;
	}
	str_pos = s_str->str + s_str->size;
	ft_memcpy(str_pos, buf, rb);
	s_str->size += rb;
}

static t_string	*asm_read_file(int fd, char *buf)
{
	t_string	*s_str;
	int			rb;

	if (!(s_str = ft_newstrs(STR_MALOC_SIZE)))
		asm_sys_error();
	while ((rb = read(fd, buf, READ_BUF_SIZE)))
	{
		if (rb == -1)
			asm_sys_error();
		asm_copy_buf_to_str(s_str, buf, (size_t)(rb));
	}
	return (s_str);
}

t_string		*asm_file_to_str(char *file_path)
{
	int			fd;
	char		*buf;
	t_string	*s_str;

	fd = asm_get_fd(file_path);
	if (!(buf = (char*)malloc(sizeof(char) * (READ_BUF_SIZE + 1))))
		asm_sys_error();
	buf[READ_BUF_SIZE] = '\0';
	s_str = asm_read_file(fd, buf);
	ft_memdel((void**)&buf);
	close(fd);
	return (s_str);
}
