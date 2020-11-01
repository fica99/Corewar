#include "corewar.h"

void		fill_arena(t_vm *vm, t_vis_arena * vs_arena)
{
	int 	i;
	t_cursor *tmp;

	tmp = vm->cursor;
	i = 0;
	while (i < MEM_SIZE)
	{
		vs_arena->arena[i].code = vm->arena[i];
		i++;
	}
	while (tmp)
	{
		vs_arena->arena[tmp->pc - 1].is_carriage = True;
		tmp = tmp->next;
	}
}

void		fill_players(t_vm *vm, t_vis_arena *vs_arena)
{
	int		i;

	i = 0;
	while (i < vm->num_players)
	{
		vs_arena->players[i].id = vm->players[i]->id;
		vs_arena->players[i].last_live = vm->players[i]->last_live;
		vs_arena->players[i].lives_in_cur_period = vm->players[i]->lives_in_cur_period;
		ft_strcpy(vs_arena->players[i].name, vm->players[i]->name);
		i++;
	}
}

void		add_struct_for_vs(t_vm *vm, t_vis_arena *vs_arena)
{
	fill_arena(vm, vs_arena);
	fill_players(vm, vs_arena);
	vs_arena->cycle = vm->cycle;
	vs_arena->cycle_to_die = vm->cycle_to_die;
	vs_arena->cycle_delta = CYCLE_DELTA;
	vs_arena->nbr_live = vm->nbr_live;
	vs_arena->max_checks = vm->max_checks;
	if (!vm->num_cursor)
		vs_arena->winner_id = vm->last_alive->id;
}