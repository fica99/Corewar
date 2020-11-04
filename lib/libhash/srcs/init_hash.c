/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:23:24 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/17 15:05:41 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_hash	*init_hash(void)
{
	t_hash	*hash;

	if (!(hash = (t_hash*)malloc(sizeof(t_hash))))
		return (NULL);
	hash->data = NULL;
	hash->hash_key = 0;
	hash->next = NULL;
	return (hash);
}
