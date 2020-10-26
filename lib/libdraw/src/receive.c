/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:48:56 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/26 20:07:18 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcp_socket.h"

int				receive_arena(t_vis_arena *arena, int socket_fd)
{
	size_t			i;
	unsigned char	buffer[sizeof(t_vis_arena)];
	int				res;
	size_t			arena_size;
	size_t			total;

	total = 0;
	arena_size = sizeof(t_vis_arena);
	while (total < arena_size)
	{
		res = recv(socket_fd, buffer + total, arena_size - total, 0);
		if (res == -1)
			error_message("Error - recv() failed");
		total += (size_t)res;
	}
	i = 0;
	*arena = deserialize_arena(buffer, &i);
	if (i != arena_size)
		error_message("Error - incorrect deserialization");
	return (0);
}
