/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:15:23 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/06 09:37:17 by aashara-         ###   ########.fr       */
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
	unsigned char	buffer[ARENA_SIZE];
	int				total;
	int				n;

	serialize_arena(buffer, arena);
	total = 0;
	while (total < ARENA_SIZE)
	{
		n = send(listenfd, buffer + total, ARENA_SIZE - total, 0);
		if (n == -1)
			error_message("Error - send() failed");
		total += n;
	}
}

int				receive_arena(t_arena *arena, int connfd)
{
	size_t			i;
	unsigned char	buffer[ARENA_SIZE];
	int				res;

	if ((res = recv(connfd, buffer, ARENA_SIZE, 0)) <= 0)
	{
		if (res == 0)
			return (-1);
		error_message("Error - recv() failed");
	}
	i = 0;
	*arena = deserialize_arena(buffer, &i);
	return (0);
}
