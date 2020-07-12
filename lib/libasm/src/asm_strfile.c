/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_strfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:34:50 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/12 15:11:23 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	asm_get_fd(char *file_path)
{
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		asm_sys_error();
	return (fd);
}

t_string	*asm_strfile(char *file_path)
{
	int		fd;

	fd = asm_get_fd(file_path);
	ft_putnbr(fd);
	return (NULL);
}
