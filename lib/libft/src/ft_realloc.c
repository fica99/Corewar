/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 00:42:23 by mmarti            #+#    #+#             */
/*   Updated: 2019/12/16 00:42:24 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *buf, size_t old, size_t new_size)
{
	unsigned char	*new_buf;

	if (!(new_buf = (unsigned char *)ft_memalloc(new_size)))
		return (NULL);
	if (buf)
		ft_memcpy(new_buf, buf, old);
	free(buf);
	return (new_buf);
}
