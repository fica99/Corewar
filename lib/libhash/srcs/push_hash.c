/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:58:11 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/08 20:17:56 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_hash	**push_hash(t_hash **table, char *hash_str, void *data, size_t size)
{
	size_t	key;
	t_hash	*hash;
	t_hash	*copy;
	size_t	index;

	if (!table || !(hash = init_hash()))
		return (NULL);
	key = djb2_hash_function(hash_str);
	index = hash_index(key, size);
	hash->data = data;
	hash->hash_key = key;
	if (table[index])
	{
		copy = table[index];
		while (copy->next)
			copy = copy->next;
		copy->next = hash;
	}
	else
		table[index] = hash;
	return (table);
}
