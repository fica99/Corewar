/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsocket.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:22:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/16 23:23:40 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSOCKET_H
# define LIBSOCKET_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include "op.h"
# include "libft.h"

# define PORT "3490"

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


/*
**					connect.c
*/
int					connect_2_server(const char *host_name);

// /*
// **	serialize.c
// */
// unsigned char		*serialize_arena(unsigned char *buffer,
// 												const t_arena *value);
// /*
// **	deserialize.c
// */
// t_arena				deserialize_arena(unsigned char *buffer, size_t *i);
// /*
// **	sendData.c
// */
// void				error_message(const char *msg);
// int					connect_to_server(void);
// void				disconnect_from_server(int listenfd);
// void				send_arena(const t_arena *arena, int listenfd);
// int					receive_arena(t_arena *arena, int connfd);
#endif
