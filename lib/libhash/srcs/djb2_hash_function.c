/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djb2_hash_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:28:35 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/17 15:10:37 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

size_t	djb2_hash_function(char *str)
{
	size_t	hash;
	int		c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}
