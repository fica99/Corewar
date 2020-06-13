/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:05:18 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/03 18:17:42 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *string1, const char *string2)
{
	int	i;
	int j;
	int k;
	int	l;

	k = 0;
	i = 0;
	l = 0;
	if (*string2 == '\0')
		return ((char*)string1);
	while (string1[i] != '\0')
	{
		k = 0;
		j = i;
		l = i;
		while (string1[l] == string2[k])
		{
			if (string2[k + 1] == '\0')
				return ((char*)&string1[j]);
			k++;
			l++;
		}
		i++;
	}
	return (NULL);
}
