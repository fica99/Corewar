/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:30:50 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/02 16:26:00 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*pointer;
	unsigned int	i;

	pointer = b;
	i = 0;
	while (n)
	{
		pointer[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (pointer);
}
