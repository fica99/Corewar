/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:34:53 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 01:34:53 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_vm *vm, t_cursor *cursor)
{
	t_player	*player;
	int32_t		player_id;

	player = NULL;
	cursor->step += OP_CODE_LEN;
	player_id = get_op_arg(vm, cursor, 1, False);
	vm->nbr_live++;
	cursor->last_live = vm->cycle;
	if (player_id <= -1 && player_id >= -((int32_t)vm->num_players))
	{
		player = vm->players[(-(player_id)) - 1];
		player->last_live = vm->cycle;
		player->lives_in_cur_period++;
		vm->last_alive = player;
	}
	if (vm->logs)
		ft_printf("P %4d | live %d\n", cursor->id, player_id);
}
