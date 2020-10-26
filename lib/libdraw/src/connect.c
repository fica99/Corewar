/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:31:54 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/26 21:14:10 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcp_socket.h"

static int	get_socket_fd(struct addrinfo *serv_info, struct addrinfo *info)
{
	static struct addrinfo			*p;
	int								socket_fd;

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
	if (!p)
	{
		fprintf(stderr, "Failed to connect\n");//ft_printf
		exit(1);
	}
	info = p;
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
															s, sizeof s);
	printf("Connecting to %s\n", s); //ft_printf
}

int			connect_server(const char *host_name)
{
	struct addrinfo	hints;
	struct addrinfo	*serv_info;
	struct addrinfo	*info;
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
		fprintf(stderr, "Getaddrinfo error: %s\n", gai_strerror(status)); // add ft_printf
		exit(1);
	}
	info = NULL;
	socket_fd = get_socket_fd(serv_info, info);
	print_connection(info);
	freeaddrinfo(serv_info);
	return (socket_fd);
}

void		disconnect_server(int socket_fd)
{
	if (close(socket_fd) < 0)
		error_message("Error - close() failed");
}
