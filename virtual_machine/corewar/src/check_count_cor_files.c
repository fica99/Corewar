/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count_cor_files.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:33:56 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 01:35:56 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_cor_file(char *name)
{
	int len;

	len = ft_strlen(name);
	if (len > 4)
	{
		if (!ft_strcmp(&name[len - 4], ".cor"))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int		check_count_cor_files(char **argv)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (is_cor_file(argv[i++]))
			count++;
	}
	return (count);
}
