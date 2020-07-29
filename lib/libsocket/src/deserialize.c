/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:37:07 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/29 13:47:49 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsocket.h"

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

static char			deserialize_char(unsigned char *buffer, size_t *i)
{
	return (buffer[(*i)++]);
}

static t_cell		deserialize_cell(unsigned char *buffer, size_t *i)
{
	t_cell	cell;

	cell.is_carriage = (t_bool)deserialize_int(buffer, i);
	cell.code = (uint8_t)deserialize_char(buffer, i);
	cell.player_id = (uint8_t)deserialize_char(buffer, i);
	(*i) += 2;
	return (cell);
}

static t_player		deserialize_player(unsigned char *buffer, size_t *i)
{
	t_player	player;
	size_t		j;

	player.last_live = deserialize_int(buffer, i);
	player.lives_in_cur_period = deserialize_int(buffer, i);
	j = 0;
	while (j < PROG_NAME_LENGTH)
	{
		player.name[j] = deserialize_char(buffer, i);
		++j;
	}
	player.id = (uint8_t)deserialize_char(buffer, i);
	(*i) += 3;
	return (player);
}

t_arena				deserialize_arena(unsigned char *buffer, size_t *i)
{
	t_arena	arena;
	size_t	j;

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
	(*i) += 3;
	return (arena);
}
