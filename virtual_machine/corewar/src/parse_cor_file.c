/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cor_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:14:23 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 16:56:40 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		add_player(t_vm *vm, t_player *player)
{
	int		i;

	i = 0;
	while (ft_strcmp(vm->players[i]->name, "\0") && i < MAX_PLAYERS)
		i++;
	vm->players[i] = player;
}

void		update_players_id(t_vm *vm)
{
	int	i;
	int id;

	i = 0;
	id = 1;
	while (i < vm->num_players)
	{
		if (vm->players[i]->id == 0)
		{
			while (find_player(vm, id))
				id++;
			vm->players[i]->id = id;
		}
		i++;
	}
}

void		check_double_ids(t_vm *vm)
{
	int			id;
	int			i;

	i = 0;
	id = 1;
	while (i < MAX_PLAYERS)
	{
		while (i >= vm->num_players && i < MAX_PLAYERS)
		{
			vm->players[i++] = NULL;
		}
		if (i >= MAX_PLAYERS)
			break ;
		vm->players[i] = find_player(vm, id++);
		i++;
	}
	vm->last_alive = vm->players[vm->num_players - 1];
}

void		parse_cor_file(int *argc, char ***argv, t_vm *vm)
{
	int			id;

	id = 0;
	if (*argc >= 3 && !ft_strcmp(**argv, "-n"))
	{
		if (!is_int(*(*argv + 1))
			|| (id = atoi_check_int(*(*argv + 1))) < 1
			|| id > MAX_PLAYERS
			|| find_player(vm, id)
			|| !is_cor_file(*(*argv + 2)))
			help();
		add_player(vm, parse_champion(*(*argv + 2), vm, id));
		(*argc) -= 3;
		(*argv) += 3;
	}
	else if (is_cor_file(**argv))
	{
		add_player(vm, parse_champion(**argv, vm, id));
		(*argc)--;
		(*argv)++;
	}
	else
		help();
}
