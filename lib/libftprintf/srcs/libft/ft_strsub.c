/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:15:02 by aashara-          #+#    #+#             */
/*   Updated: 2019/04/03 17:59:03 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	i;

	if (s)
	{
		i = 0;
		s1 = ft_memalloc(len + 1);
		if (s1)
		{
			while (i < len)
			{
				s1[i] = s[start + i];
				i++;
			}
			return (s1);
		}
	}
	return (NULL);
}
