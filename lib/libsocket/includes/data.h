/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara <aashara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 23:17:54 by aashara           #+#    #+#             */
/*   Updated: 2020/10/17 23:19:04 by aashara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

#include "op.h"
#include "libft.h"

typedef struct		s_vis_cell
{
	t_bool			is_carriage;
	uint8_t			code;
	uint8_t			player_id;
}					t_vis_cell;

typedef struct		s_vis_player
{
	int				last_live;
	int				lives_in_cur_period;
	char			name[PROG_NAME_LENGTH];
	uint8_t			id;
}					t_vis_player;

typedef struct		s_vis_arena
{
	t_vis_player	players[MAX_PLAYERS];
	t_vis_cell		arena[MEM_SIZE];
	int				cycle;
	int				cycle_to_die;
	int				cycle_delta;
	int				nbr_live;
	int				max_checks;
	uint8_t			winner_id;
}					t_vis_arena;

#endif
