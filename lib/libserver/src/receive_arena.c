/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:48:51 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/27 21:06:09 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_bool				receive_arena(t_vis_arena *arena, int connfd)
{
	unsigned char	buffer[sizeof(t_vis_arena) + 1];
	int				res;
	size_t			arena_size;
	size_t			total;

	total = 0;
	arena_size = sizeof(t_vis_arena);
	while (total < arena_size)
	{
		if ((res = recv(connfd, buffer + total, arena_size - total, 0)) < 0)
			error_message("Error - recv() failed");
		if (!res)
			return (False);
		total += (size_t)res;
	}
	*arena = deserialize_arena(buffer);
	return (True);
}
