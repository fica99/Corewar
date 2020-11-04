/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:34:48 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 01:34:48 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lfork(t_vm *vm, t_cursor *cursor)
{
	int32_t		addr;
	t_cursor	*new;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, True);
	new = copy_cursor(cursor, addr);
	add_cursor(&(vm->cursor), new);
	vm->num_cursor++;
	if (vm->logs)
		ft_printf("P %4d | lfork %d (%d)\n",
					cursor->id,
					addr,
					cursor->pc + addr);
}
