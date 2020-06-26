/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:15:23 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/27 00:59:25 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void			error_message(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

static int		sendall(int s, char *buf, int len, int flags)
{
	int	total;
	int	n;

	total = 0;
	while (total < len)
	{
		n = send(s, buf + total, len - total, flags);
		if (n == -1)
			break ;
		total += n;
	}
	return (n == -1 ? -1 : total);
}

void			send_arena(const t_arena *arena)
{
	unsigned char		buffer[ARENA_SIZE + 1];
	int					listenfd;
	struct sockaddr_un	srvr_name;

	serialize_arena(buffer, arena);
	if ((listenfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
		error_message("Socket() failed");
	srvr_name.sun_family = AF_UNIX;
	ft_strcpy(srvr_name.sun_path, SERVER_PATH);
	if (connect(listenfd, (struct sockaddr*)&srvr_name, sizeof(srvr_name)) < 0)
		error_message("Connect() failed");
	if (sendall(listenfd, (char*)buffer, sizeof(buffer), 0) < 0)
		error_message("Send() failed");
	if (close(listenfd) < 0)
		error_message("Close() failed");
}

t_arena			receive_arena(int listenfd)
{
	int				connfd;
	size_t			i;
	unsigned char	buffer[ARENA_SIZE + 1];

	connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
	if (recv(connfd, buffer, sizeof(buffer), 0) < 0)
		error_message("Recv() failed");
	close(connfd);
	i = 0;
	return (deserialize_arena(buffer, &i));
}
