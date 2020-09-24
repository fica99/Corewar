/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:58:11 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/17 17:26:34 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_hash	*set_hash(char *hash_str, char *data, size_t size)
{
	size_t	key;
	t_hash	*hash;

	if (!hash_str || !data || size == 0)
		return (NULL);
	key = djb2_hash_function(hash_str);
	if (!(hash = init_hash()))
		return (NULL);
	hash->data = data;
	hash->hash_key = key;
	return (hash);
}
