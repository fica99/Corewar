/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:15:36 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/17 14:41:32 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_hash	**init_hash_table(size_t size)
{
	t_hash	**table;
	size_t	i;

	if (!(table = (t_hash**)malloc(sizeof(t_hash*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i <= size)
		table[i++] = NULL;
	return (table);
}
