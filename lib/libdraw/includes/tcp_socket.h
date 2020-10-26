/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcp_socket.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:22:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/26 21:11:23 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_H
# define SOCKET_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdio.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <arpa/inet.h>
# include "libft.h"
# include "op.h"
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
int					connect_server(const char *host_name);
void				disconnect_server(int socket_fd);
/*
**					send.c
*/
void				error_message(const char *msg);
void				send_data(const t_vis_arena *arena, int socket_fd);
/*
**					serialize.c
*/
unsigned char		*serialize_arena(unsigned char *buffer,
											const t_vis_arena *value);
/*
**					deserialize.c
*/
t_vis_arena			deserialize_arena(unsigned char *buffer, size_t *i);
/*
**					receive.c
*/
int					receive_arena(t_vis_arena *arena, int socket_fd);
/*
**					create_server.c
*/
#endif
