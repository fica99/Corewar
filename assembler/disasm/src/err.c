/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:53:36 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/29 21:46:06 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void	*file_error(const char *fname, const char *mes)
{
	ft_putstr_fd("disasm: ", STDERR_FILENO);
	ft_putstr_fd(fname, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(mes, STDERR_FILENO);
	return (NULL);
}

void	fatal_error(const char *mes)
{
	if (mes)
	{
		ft_putstr_fd("disasm: ", STDERR_FILENO);
		ft_putendl_fd(mes, STDERR_FILENO);
	}
	exit(1);
}
