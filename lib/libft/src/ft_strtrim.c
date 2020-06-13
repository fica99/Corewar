/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:41:22 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/03 16:01:19 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = -1;
	j = ft_strlen((char*)s) - 1;
	while (s[j] == '\n' || s[j] == ' ' || s[j] == '\t')
		j--;
	while (s[++i] == '\n' || s[i] == ' ' || s[i] == '\t')
		j--;
	if (j <= 0)
		j = 0;
	s1 = ft_strnew(j + 1);
	if (!s1)
		return (NULL);
	s += i;
	i = -1;
	while (++i <= j)
	{
		s1[i] = *s;
		s++;
	}
	return (s1);
}
