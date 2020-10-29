/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:24:19 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/02 16:48:04 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pointer1;
	unsigned char	*pointer2;
	unsigned int	i;

	i = 0;
	if (n == 0 || s1 == s2)
		return (0);
	pointer1 = (unsigned char*)s1;
	pointer2 = (unsigned char*)s2;
	while (n)
	{
		if (pointer1[i] != pointer2[i])
			return (pointer1[i] - pointer2[i]);
		n--;
		i++;
	}
	return (0);
}
