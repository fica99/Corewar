/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 23:16:58 by aashara           #+#    #+#             */
/*   Updated: 2020/10/26 20:03:36 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcp_socket.h"

void			error_message(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void			send_data(const t_vis_arena *arena, int socket_fd)
{
	unsigned char	buffer[sizeof(t_vis_arena)];
	size_t			total;
	int				n;
	size_t			arena_size;

	arena_size = sizeof(t_vis_arena);
	ft_bzero((void*)buffer, arena_size);
	serialize_arena(buffer, arena);
	total = 0;
	while (total < arena_size)
	{
		n = send(socket_fd, buffer + total, arena_size - total, 0);
		if (n == -1)
			error_message("Error - send() failed");
		total += (size_t)n;
	}
}
