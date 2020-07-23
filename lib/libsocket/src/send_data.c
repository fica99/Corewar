/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:15:23 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/23 19:26:49 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsocket.h"

void			error_message(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int				connect_to_server(void)
{
	int					listenfd;
	struct sockaddr_un	srvr_name;

	if ((listenfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
		error_message("Error - socket() failed");
	srvr_name.sun_family = AF_UNIX;
	ft_strcpy(srvr_name.sun_path, SERVER_PATH);
	if (connect(listenfd, (struct sockaddr*)&srvr_name, sizeof(srvr_name)) < 0)
		error_message("Error - connect() failed");
	return (listenfd);
}

void			disconnect_from_server(int listenfd)
{
	if (close(listenfd) < 0)
		error_message("Error - close() failed");
}

void			send_arena(const t_arena *arena, int listenfd)
{
	unsigned char	buffer[sizeof(t_arena)];
	size_t			total;
	int				n;
	size_t			arena_size;

	arena_size = sizeof(t_arena);
	ft_bzero((void*)buffer, arena_size);
	serialize_arena(buffer, arena);
	total = 0;
	while (total < arena_size)
	{
		n = send(listenfd, buffer + total, arena_size - total, 0);
		if (n == -1)
			error_message("Error - send() failed");
		total += n;
	}
}

int				receive_arena(t_arena *arena, int connfd)
{
	size_t			i;
	unsigned char	buffer[sizeof(t_arena)];
	int				res;

	if ((res = recv(connfd, buffer, sizeof(t_arena), 0)) <= 0)
	{
		if (res == 0)
			return (-1);
		error_message("Error - recv() failed");
	}
	i = 0;
	*arena = deserialize_arena(buffer, &i);
	return (0);
}
