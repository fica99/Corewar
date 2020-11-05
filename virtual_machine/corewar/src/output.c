/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:35:36 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 02:42:46 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_log(t_vm *vm, t_cursor *cursor)
{
	uint32_t	i;

	ft_printf("ADV %d (%0.4p -> %0.4p) ", cursor->step,
				cursor->pc, cursor->pc + cursor->step);
	i = 0;
	while (i < cursor->step)
	{
		ft_printf("%02x ", vm->arena[(cursor->pc + i)]);
		i++;
	}
	ft_printf("\n");
}

void	output_arena(unsigned char *arena, int print_mode)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.4p : ", i);
		j = 0;
		while (j < print_mode)
		{
			ft_printf("%.2x ", arena[i + j]);
			j++;
		}
		ft_printf("\n");
		i += print_mode;
	}
}

void	dump_output(t_vm *vm)
{
	if (vm->dump == vm->cycle)
	{
		output_arena(vm->arena, vm->dump_print_mode);
		exit(0);
	}
}
