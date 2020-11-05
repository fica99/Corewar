/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:33:08 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 02:15:56 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	*find_player(t_vm *vm, int id)
{
	int		i;

	i = 0;
	while (i < vm->num_players)
	{
		if (id == vm->players[i]->id)
			return (vm->players[i]);
		i++;
	}
	return (NULL);
}

void		parse_dump_flag(int *argc, char ***argv, t_vm *vm)
{
	if (!vm->dump_print_mode && *argc >= 2 &&
		is_int(*(*argv + 1)) && vm->num_players)
	{
		if ((vm->dump = ft_atoi(*(*argv + 1))) < 0)
			vm->dump = -1;
		if (!ft_strcmp(**argv, "-d"))
			vm->dump_print_mode = 64;
		else
			vm->dump_print_mode = 32;
		(*argc) -= 2;
		(*argv) += 2;
	}
	else
		help();
}

void		parse_log_flag(int *argc, char ***argv, t_vm *vm)
{
	vm->logs = True;
	(*argc) -= 1;
	(*argv) += 1;
}

void		parse_aff_flag(int *argc, char ***argv, t_vm *vm)
{
	vm->aff = True;
	(*argc)--;
	(*argv)++;
}

void		parse_args(char **argv, int argc, t_vm *vm)
{
	while (argc >= 1)
	{
		if ((!ft_strcmp(*argv, "-n") || is_cor_file(*argv)))
			parse_cor_file(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-dump") || !ft_strcmp(*argv, "-d"))
			parse_dump_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-v"))
			parse_vs_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-l"))
			parse_log_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-a"))
			parse_aff_flag(&argc, &argv, vm);
		else
			help();
	}
	if (vm->num_players < 1 || vm->num_players > MAX_PLAYERS)
		ft_exit("Error <Number of champions "
			"more then MAX_PLAYERS or less then 1>");
	update_players_id(vm);
	check_double_ids(vm);
}
