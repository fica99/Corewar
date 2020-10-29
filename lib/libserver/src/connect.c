/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:31:54 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 21:48:24 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			get_socket_fd(struct addrinfo *serv_info, struct addrinfo **info)
{
	struct addrinfo	*p;
	int				socket_fd;

	p = serv_info;
	while (p)
	{
		socket_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (socket_fd != -1)
			break ;
		p = p->ai_next;
	}
	if (!p)
	{
		ft_dprintf(STDERR_FILENO, "Failed to get socket file descriptor\n");
		exit(1);
	}
	*info = p;
	return (socket_fd);
}

static void	*get_in_addr(const struct sockaddr *info)
{
	if (info->sa_family == AF_INET)
		return (&(((struct sockaddr_in*)info)->sin_addr));
	return (&(((struct sockaddr_in6*)info)->sin6_addr));
}

static void	print_connection(const struct addrinfo *info)
{
	char	s[INET6_ADDRSTRLEN];

	inet_ntop(info->ai_family, get_in_addr((struct sockaddr *)info->ai_addr),
														s, INET6_ADDRSTRLEN);
	ft_printf("Connecting to %s\n", s);
}

int			connect_server(const char *host_name)
{
	struct addrinfo	hints;
	struct addrinfo	*serv_info;
	struct addrinfo	*info;
	int				socket_fd;
	int				rv;

	ft_bzero((void*)&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if ((rv = getaddrinfo(host_name, PORT, &hints, &serv_info)) == -1)
	{
		ft_dprintf(STDERR_FILENO, "Getaddrinfo error: %s\n", gai_strerror(rv));
		exit(1);
	}
	socket_fd = get_socket_fd(serv_info, &info);
	while (connect(socket_fd, info->ai_addr, info->ai_addrlen) == -1)
	{
		close(socket_fd);
		socket_fd = get_socket_fd(info->ai_next, &info);
	}
	print_connection(info);
	freeaddrinfo(serv_info);
	return (socket_fd);
}

void		disconnect_server(int socket_fd)
{
	if (close(socket_fd) < 0)
		error_message("Error - close() failed");
}
