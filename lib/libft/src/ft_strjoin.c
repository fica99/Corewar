/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:22:10 by aashara-          #+#    #+#             */
/*   Updated: 2019/03/01 19:21:52 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;

	if (s1 && s2)
	{
		arr = (char*)malloc(sizeof(char)
			* (ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1));
		if (arr)
		{
			ft_strcpy(arr, (char*)s1);
			ft_strcat(arr, (char*)s2);
			return (arr);
		}
	}
	return (NULL);
}
