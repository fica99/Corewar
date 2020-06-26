/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:22:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/27 00:59:35 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/un.h>
# include <errno.h>
# include <unistd.h>
# include "op.h"
# include "libft.h"

# define SERVER_PATH "/tmp/server.soc"
# define ARENA_SIZE 12856

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
unsigned char		*serialize_arena(unsigned char *buffer,
												const t_arena *value);
/*
**	deserialize.c
*/
t_arena				deserialize_arena(unsigned char *buffer, size_t *i);
/*
**	sendData.c
*/
void				error_message(const char *msg);
void				send_arena(const t_arena *arena);
t_arena				receive_arena(int listenfd);
#endif
