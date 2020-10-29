/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:07:50 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/03 22:28:40 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*pointer;
	unsigned int	i;

	i = 0;
	pointer = (unsigned char*)arr;
	while (n)
	{
		if (pointer[i] == (unsigned char)c)
			return (&pointer[i]);
		i++;
		n--;
	}
	return (NULL);
}
