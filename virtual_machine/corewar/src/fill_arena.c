/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:34:01 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 01:52:05 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		add_code_of_players(t_vm *vm)
{
	int			i;
	int			j;
	int			pc;

	i = 0;
	pc = 0;
	while (i < vm->num_players)
	{
		j = pc;
		while (vm->players[i]->code_size--)
			vm->vs_arena.arena[j++].player_id = vm->players[i]->id;
		i++;
		pc += MEM_SIZE / vm->num_players;
	}
}

void		fill_arena(t_vm *vm)
{
	int			i;
	t_cursor	*tmp;

	tmp = vm->cursor;
	i = 0;
	while (i < MEM_SIZE)
	{
		vm->vs_arena.arena[i].code = vm->arena[i];
		i++;
	}
	while (tmp)
	{
		vm->vs_arena.arena[tmp->pc].is_carriage = True;
		tmp = tmp->next;
	}
}

void		fill_players(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < vm->num_players)
	{
		vm->vs_arena.players[i].id = vm->players[i]->id;
		vm->vs_arena.players[i].last_live = vm->players[i]->last_live;
		vm->vs_arena.players[i].lives_in_cur_period = \
				vm->players[i]->lives_in_cur_period;
		ft_strcpy(vm->vs_arena.players[i].name, vm->players[i]->name);
		i++;
	}
}

void		add_struct_for_vs(t_vm *vm)
{
	fill_arena(vm);
	fill_players(vm);
	vm->vs_arena.cycle = vm->cycle;
	vm->vs_arena.cycle_to_die = vm->cycle_to_die;
	vm->vs_arena.cycle_delta = CYCLE_DELTA;
	vm->vs_arena.nbr_live = vm->nbr_live;
	vm->vs_arena.max_checks = (int)vm->max_checks;
	if (!vm->num_cursor)
		vm->vs_arena.winner_id = vm->last_alive->id;
}
