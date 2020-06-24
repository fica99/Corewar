#ifndef VISUAL_H
#define VISUAL_H

#include <stdint.h>
#include <stdio.h>
#include "op.h"

typedef enum
{
					False = 0,
					True = 1
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
unsigned char	*serialize_int(unsigned char *buffer, int value);
unsigned char	*serialize_char(unsigned char *buffer, char value);
unsigned char	*serialize_cell(unsigned char *buffer, t_cell value);
unsigned char	*serialize_player(unsigned char *buffer, t_player value);
unsigned char	*serialize_arena(unsigned char *buffer, t_arena value);
#endif
