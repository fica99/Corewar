/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:34:17 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 01:34:17 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_vm *vm, t_cursor *cursor)
{
	int32_t reg;
	int32_t ascii_symbol;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	reg = get_byte(vm, cursor->step, cursor->pc);
	ascii_symbol = cursor->reg[reg - 1];
	cursor->step += REG_LEN;
	if (vm->aff)
		ft_printf("Aff: %c\n", (char)ascii_symbol);
}
