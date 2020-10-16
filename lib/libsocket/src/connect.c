/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:31:54 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/16 23:22:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsocket.h"

static int	get_socket_fd(struct addrinfo *serv_info)
{
	struct addrinfo	*p;
	int				socket_fd;

	p = serv_info;
	while (p)
	{
		socket_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (socket_fd != -1)
		{
			if (connect(socket_fd, p->ai_addr, p->ai_addrlen) == -1)
				close(socket_fd);
			else
				break;
		}
		p = p->ai_next;
	}
	return (socket_fd);
}

int	connect_2_server(const char *host_name)
{
	struct addrinfo	hints;
	struct addrinfo	*serv_info;
	int				status;
	int				socket_fd;

	if (!host_name)
		return (-1);
	ft_bzero((void*)&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	status = getaddrinfo(host_name, PORT, &hints, &serv_info);
	if (status == -1)
	{
		fprintf(STDERR_FILENO, "Getaddrinfo error: %s\n", gai_strerror(status));//add ft_fprintf
		exit(1);
	}
	socket_fd = get_socket_fd(serv_info);
	freeaddrinfo(serv_info);
}
