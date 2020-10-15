/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:53:32 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/15 16:44:29 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void	*xmalloc(size_t size)
{
	void *ptr;

	if (!(ptr = ft_memalloc(size)))
		fatal_error(strerror(errno));
	return (ptr);
}
