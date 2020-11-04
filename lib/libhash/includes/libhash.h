/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libhash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:58:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/24 20:28:11 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBHASH_H
# define LIBHASH_H

# include "libft.h"
# include <stdlib.h>

typedef struct		s_hash
{
	void			*data;
	size_t			hash_key;
	struct s_hash	*next;
}					t_hash;

t_hash				**free_hash_table(t_hash **table, size_t len,
char free_data);
t_hash				**init_hash_table(size_t size);
t_hash				*init_hash(void);
size_t				hash_index(size_t key, size_t size);
size_t				djb2_hash_function(char *str);
t_hash				**push_hash(t_hash **table, char *hash_str,
void *data, size_t size);
void				*get_hash_data(t_hash **table, char *hash_str,
size_t size);
#endif
