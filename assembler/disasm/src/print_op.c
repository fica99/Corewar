/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:58:58 by aashara-          #+#    #+#             */
/*   Updated: 2020/11/06 18:42:02 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static char	op_sym(uint8_t op_type)
{
	if (op_type == T_DIR)
		return ('%');
	else if (op_type == T_REG)
		return ('r');
	return (0);
}

void		print_op(t_op *op, int fd)
{
	int		i;
	t_bool	first;
	char	tmp;

	first = True;
	i = 0;
	ft_putstr_fd(op->name, fd);
	ft_putchar_fd(' ', fd);
	while (i < op->args_num)
	{
		if (!first)
			ft_putstr_fd(", ", fd);
		first = False;
		if ((tmp = op_sym(op->args_types[i])))
			ft_putchar_fd(tmp, fd);
		ft_putnbr_fd((int)op->args_val[i], fd);
		i++;
	}
}
