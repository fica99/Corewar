/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara <aashara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:22:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/18 19:07:51 by aashara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_H
# define SOCKET_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdio.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include "data.h"
# include "tpl.h"
# define PORT "3490"

/*
**					connect.c
*/
int					connect_2_server(const char *host_name);
/*
**					send.c
*/
void				send_data(const t_vis_arena *arena);
#endif
