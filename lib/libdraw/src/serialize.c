/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:11:30 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/26 20:01:34 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcp_socket.h"

static unsigned char	*serialize_int(unsigned char *buffer, int value)
{
	buffer[0] = value >> 24;
	buffer[1] = value >> 16;
	buffer[2] = value >> 8;
	buffer[3] = value;
	return (buffer + 4);
}

static unsigned char	*serialize_char(unsigned char *buffer, char value)
{
	buffer[0] = value;
	return (buffer + 1);
}

static unsigned char	*serialize_cell(unsigned char *buffer,
													const t_vis_cell *value)
{
	unsigned char	*start;

	start = buffer;
	buffer = serialize_int(buffer, (int)value->is_carriage);
	buffer = serialize_char(buffer, (char)value->code);
	buffer = serialize_char(buffer, (char)value->player_id);
	return (start + sizeof(t_vis_cell));
}

static unsigned char	*serialize_player(unsigned char *buffer,
												const t_vis_player *value)
{
	size_t			i;
	unsigned char	*start;

	start = buffer;
	buffer = serialize_int(buffer, value->last_live);
	buffer = serialize_int(buffer, value->lives_in_cur_period);
	i = 0;
	while (i < PROG_NAME_LENGTH)
	{
		buffer = serialize_char(buffer, value->name[i]);
		++i;
	}
	buffer = serialize_char(buffer, (char)value->id);
	return (start + sizeof(t_vis_player));
}

unsigned char			*serialize_arena(unsigned char *buffer,
												const t_vis_arena *value)
{
	size_t			i;
	unsigned char	*start;

	start = buffer;
	i = 0;
	while (i < MAX_PLAYERS)
	{
		buffer = serialize_player(buffer, value->players + i);
		++i;
	}
	i = 0;
	while (i < MEM_SIZE)
	{
		buffer = serialize_cell(buffer, &value->arena[i]);
		++i;
	}
	buffer = serialize_int(buffer, value->cycle);
	buffer = serialize_int(buffer, value->cycle_to_die);
	buffer = serialize_int(buffer, value->cycle_delta);
	buffer = serialize_int(buffer, value->nbr_live);
	buffer = serialize_int(buffer, value->max_checks);
	buffer = serialize_char(buffer, (char)value->winner_id);
	return (start + sizeof(t_vis_arena));
}
