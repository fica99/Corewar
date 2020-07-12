/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 16:18:44 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/12 15:10:49 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	asm_prog_error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(1);
}

void	asm_sys_error(void)
{
	t_string	*s_str;
	char 		*error;

	error = strerror(errno);
	s_str = ft_strmulsub("Error: ?", 100, error);
	ft_putstr_fd(s_str->str, STDERR_FILENO);
	exit(1);
}
