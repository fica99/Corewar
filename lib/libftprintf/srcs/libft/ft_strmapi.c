/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:29:44 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/03 22:23:12 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*arr;

	if (s && f)
	{
		i = 0;
		arr = ft_memalloc(ft_strlen((char*)s) + 1);
		if (arr)
		{
			while (s[i] != '\0')
			{
				arr[i] = f(i, s[i]);
				i++;
			}
			return (arr);
		}
	}
	return (NULL);
}
