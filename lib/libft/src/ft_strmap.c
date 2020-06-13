/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:12:31 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/03 22:22:56 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*arr;
	int		i;

	if (s && f)
	{
		i = 0;
		arr = ft_memalloc(ft_strlen((char*)s) + 1);
		if (arr)
		{
			while (*s != '\0')
			{
				arr[i] = f(*s);
				s++;
				i++;
			}
			return (arr);
		}
	}
	return (NULL);
}
