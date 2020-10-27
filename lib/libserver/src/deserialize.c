/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:42:40 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/26 19:44:34 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcp_socket.h"

static int			deserialize_int(unsigned char *buffer, size_t *i)
{
	int	value;

	value = 0;
	value |= buffer[(*i)++] << 24;
	value |= buffer[(*i)++] << 16;
	value |= buffer[(*i)++] << 8;
	value |= buffer[(*i)++];
	return (value);
}

static char				deserialize_char(unsigned char *buffer, size_t *i)
{
	return (buffer[(*i)++]);
}

static t_vis_cell		deserialize_cell(unsigned char *buffer, size_t *i)
{
	t_vis_cell	cell;

	cell.is_carriage = (t_bool)deserialize_int(buffer, i);
	cell.code = (uint8_t)deserialize_char(buffer, i);
	cell.player_id = (uint8_t)deserialize_char(buffer, i);
	return (cell);
}

static t_vis_player		deserialize_player(unsigned char *buffer, size_t *i)
{
	t_vis_player	player;
	size_t			j;

	player.last_live = deserialize_int(buffer, i);
	player.lives_in_cur_period = deserialize_int(buffer, i);
	j = 0;
	while (j < PROG_NAME_LENGTH)
	{
		player.name[j] = deserialize_char(buffer, i);
		++j;
	}
	player.id = (uint8_t)deserialize_char(buffer, i);
	return (player);
}

t_vis_arena				deserialize_arena(unsigned char *buffer, size_t *i)
{
	t_vis_arena	arena;
	size_t		j;

	j = 0;
	while (j < MAX_PLAYERS)
	{
		arena.players[j] = deserialize_player(buffer, i);
		++j;
	}
	j = 0;
	while (j < MEM_SIZE)
	{
		arena.arena[j] = deserialize_cell(buffer, i);
		++j;
	}
	arena.cycle = deserialize_int(buffer, i);
	arena.cycle_to_die = deserialize_int(buffer, i);
	arena.cycle_delta = deserialize_int(buffer, i);
	arena.nbr_live = deserialize_int(buffer, i);
	arena.max_checks = deserialize_int(buffer, i);
	arena.winner_id = (uint8_t)deserialize_char(buffer, i);
	return (arena);
}
