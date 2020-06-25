/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:22:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/25 20:31:08 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <stdint.h>
# include <stdio.h>
# include "op.h"

typedef enum		e_bool
{
	False = 0,
	True = 1,
}					t_bool;

typedef struct		s_cell
{
	uint8_t			code;
	uint8_t			player_id;
	t_bool			is_carriage;
}					t_cell;

typedef struct		s_player
{
	uint8_t			id;
	char			name[PROG_NAME_LENGTH];
	int				last_live;
	int				lives_in_cur_period;

}					t_player;

typedef struct		s_arena
{
	int				cycle;
	int				cycle_to_die;
	int				cycle_delta;
	int				nbr_live;
	int				max_checks;
	t_player		players[MAX_PLAYERS];
	t_cell			arena[MEM_SIZE];

}					t_arena;

/*
**	serialize.c
*/
unsigned char		*serialize_int(unsigned char *buffer, int value);
unsigned char		*serialize_char(unsigned char *buffer, char value);
unsigned char		*serialize_cell(unsigned char *buffer, t_cell value);
unsigned char		*serialize_player(unsigned char *buffer, t_player value);
unsigned char		*serialize_arena(unsigned char *buffer, t_arena value);
/*
**	deserialize.c
*/
int					deserialize_int(unsigned char *buffer, size_t *i);
char				deserialize_char(unsigned char *buffer, size_t *i);
t_cell				deserialize_cell(unsigned char *buffer, size_t *i);
t_player			deserialize_player(unsigned char *buffer, size_t *i);
t_arena				deserialize_arena(unsigned char *buffer, size_t *i);
#endif
