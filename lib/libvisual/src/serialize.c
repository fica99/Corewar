/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara <aashara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 00:25:57 by aashara           #+#    #+#             */
/*   Updated: 2020/06/25 01:09:16 by aashara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

unsigned char	*serialize_int(unsigned char *buffer, int value)
{
	buffer[0] = value >> 24;
	buffer[1] = value >> 16;
	buffer[2] = value >> 8;
	buffer[3] = value;
	return (buffer + 4);
}

unsigned char	*serialize_char(unsigned char *buffer, char value)
{
	buffer[0] = value;
	return (buffer + 1);
}

unsigned char	*serialize_cell(unsigned char *buffer, t_cell value)
{
	buffer = serialize_char(buffer, (char)value.code);
	buffer = serialize_char(buffer, (char)value.player_id);
	buffer = serialize_char(buffer, (char)value.is_carriage);
	return (buffer);
}

unsigned char	*serialize_player(unsigned char *buffer, t_player value)
{
	size_t	i;

	buffer = serialize_char(buffer, (char)value.id);
	i = 0;
	while (i < PROG_NAME_LENGTH) {
		buffer = serialize_char(buffer, value.name[i]);
		++i;
	}
	buffer = serialize_int(buffer, value.last_live);
	buffer = serialize_int(buffer, value.lives_in_cur_period);
	return (buffer);
}

unsigned char	*serialize_arena(unsigned char *buffer, t_arena value)
{
	size_t	i;

	buffer = serialize_int(buffer, value.cycle);
	buffer = serialize_int(buffer, value.cycle_to_die);
	buffer = serialize_int(buffer, value.cycle_delta);
	buffer = serialize_int(buffer, value.nbr_live);
	buffer = serialize_int(buffer, value.max_checks);
	i = 0;
	while (i < MAX_PLAYERS) {
		buffer = serialize_player(buffer, value.players[i]);
		++i;
	}
	i = 0;
	while (i < MEM_SIZE) {
		buffer = serialize_cell(buffer, value.arena[i]);
		++i;
	}
	return (buffer);
}
