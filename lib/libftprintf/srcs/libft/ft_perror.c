/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:19:38 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/24 16:19:41 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_perror(const char *msg, int is_exit)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	if (is_exit)
		exit(EXIT_FAILURE);
}
