/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 23:16:58 by aashara           #+#    #+#             */
/*   Updated: 2020/10/27 21:06:13 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			error_message(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void			send_arena(const t_vis_arena *arena, int socket_fd)
{
	unsigned char	buffer[sizeof(t_vis_arena) + 1];
	size_t			total;
	int				n;
	size_t			arena_size;

	arena_size = sizeof(t_vis_arena);
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
