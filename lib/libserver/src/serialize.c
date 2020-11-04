/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:11:30 by aashara-          #+#    #+#             */
/*   Updated: 2020/11/03 18:19:57 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static unsigned char	*serialize_int(unsigned char *buffer, int value)
{
	size_t	i;
	size_t	size_int;

	i = 0;
	size_int = sizeof(int);
	while (i < size_int)
	{
		buffer[i] = value >> ((size_int - i - 1) * 8);
		++i;
	}
	return (buffer + i);
}

static unsigned char	*serialize_char(unsigned char *buffer, char value)
{
	size_t	i;
	size_t	size_char;

	i = 0;
	buffer[i++] = value;
	size_char = sizeof(char);
	while (i < size_char)
		buffer[i++] = '\0';
	return (buffer + i);
}

static unsigned char	*serialize_cell(unsigned char *buffer,
													const t_vis_cell *value)
{
	unsigned char	*start;
	size_t			i;
	size_t			size_cell;

	start = buffer;
	buffer = serialize_int(buffer, (int)value->is_carriage);
	buffer = serialize_char(buffer, (char)value->code);
	buffer = serialize_char(buffer, (char)value->player_id);
	i = buffer - start;
	size_cell = sizeof(t_vis_cell);
	while (i < size_cell)
		start[i++] = '\0';
	return (start + i);
}

static unsigned char	*serialize_player(unsigned char *buffer,
												const t_vis_player *value)
{
	size_t			i;
	unsigned char	*start;
	size_t			size_player;

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
	size_player = sizeof(t_vis_player);
	i = buffer - start;
	while (i < size_player)
		start[i++] = '\0';
	return (start + i);
}

unsigned char			*serialize_arena(unsigned char *buffer,
												const t_vis_arena *value)
{
	size_t			i;
	unsigned char	*start;
	size_t			arena_size;

	start = buffer;
	i = 0;
	while (i < MAX_PLAYERS)
	{
		buffer = serialize_player(buffer, value->players + i);
		++i;
	}
	i = 0;
	while (i < MEM_SIZE)
		buffer = serialize_cell(buffer, &value->arena[i++]);
	buffer = serialize_int(buffer, value->cycle);
	buffer = serialize_int(buffer, value->cycle_to_die);
	buffer = serialize_int(buffer, value->cycle_delta);
	buffer = serialize_int(buffer, value->nbr_live);
	buffer = serialize_int(buffer, value->max_checks);
	buffer = serialize_char(buffer, (char)value->winner_id);
	i = buffer - start;
	arena_size = sizeof(t_vis_arena);
	while (i < arena_size)
		start[i++] = '\0';
	return (start + i);
}
