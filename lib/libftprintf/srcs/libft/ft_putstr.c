/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:50:29 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/14 09:24:44 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	size_t	i;
	int		res;

	if (s)
	{
		i = ft_strlen(s);
		res = write(1, s, i);
		if (res == -1)
			return ;
	}
}
