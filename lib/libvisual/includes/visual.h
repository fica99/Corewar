#ifndef VISUAL_H
#define VISUAL_H

#include <stdint.h>
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
	char			name[PROG_NAME_LENGT];
	uint32_t		last_live;
	uint16_t		lives_in_cur_period;

}					t_player;

typedef struct		s_arena
{
	uint32_t		cycle;
	int16_t			cycle_to_die;
	uint16_t		cycle_delta;
	uint16_t		nbr_live;
	uint16_t		max_checks;
	t_player		players[MAX_PLAYERS];
	t_cell			arena[MEM_SIZE];

}					t_arena;

#endif
