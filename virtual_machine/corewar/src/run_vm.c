/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:33:16 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 02:22:15 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		set_cycle_to_exec(t_vm *vm, t_cursor *cursor)
{
	cursor->op_code = vm->arena[cursor->pc];
	if (cursor->op_code >= 0x01 && cursor->op_code <= 0x10)
		cursor->cycles_to_exec = g_op[cursor->op_code - 1].cycles;
}

void		op_code_for_cursor(t_vm *vm, t_cursor *cursor)
{
	t_op		*op;

	if (cursor->cycles_to_exec == 0)
		set_cycle_to_exec(vm, cursor);
	if (cursor->cycles_to_exec > 0)
		cursor->cycles_to_exec--;
	if (cursor->cycles_to_exec == 0)
	{
		op = NULL;
		if (cursor->op_code >= 0x01 && cursor->op_code <= 0x10)
			op = &g_op[cursor->op_code - 1];
		if (op)
		{
			parse_types_args(vm, op, cursor);
			if (val_args_types(cursor, op) && validate_args(vm, cursor, op))
				op->func(vm, cursor);
			else
				cursor->step += calc_step(cursor, op);
			if (cursor->step && vm->logs)
				print_log(vm, cursor);
		}
		else
			cursor->step = ARGS_CODE_LEN;
		move_cursor(cursor);
	}
}

void		false_cursor(t_vis_arena *vs_arena)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
		vs_arena->arena[i++].is_carriage = False;
}

void		exec(t_vm *vm)
{
	t_cursor		*cursor;

	dump_output(vm);
	vm->cycle++;
	vm->cycle_after_check++;
	if (vm->logs)
		ft_printf("It is now cycle %zd\n", vm->cycle);
	cursor = vm->cursor;
	while (cursor)
	{
		op_code_for_cursor(vm, cursor);
		cursor = cursor->next;
	}
}

void		run_vm(t_vm *vm)
{
	if (vm->vs)
	{
		vm->listenfd = connect_server(vm->vs_ip);
		add_code_of_players(vm);
	}
	while (vm->num_cursor)
	{
		exec(vm);
		if (vm->cycle_to_die == vm->cycle_after_check || vm->cycle_to_die <= 0)
			check_map(vm);
		if (vm->vs)
		{
			false_cursor(&vm->vs_arena);
			add_struct_for_vs(vm);
			send_arena(&vm->vs_arena, vm->listenfd);
		}
	}
	if (vm->vs)
		disconnect_server(vm->listenfd);
}
