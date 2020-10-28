/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_support_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:21:14 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/28 20:40:31 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	asm_add_null_in_bd(t_asm_bin_data *bin_data, int bytes)
{
	bin_data->add(bin_data, 0, 2 * bytes);
}

void	asm_print_str_filetostr(char *str)
{
	ft_putendl_fd(str, STDOUT_FILENO);
}

// void	asm_print_opershash(t_hash **opers_hash)
// {
// 	int		i;
// 	char	*data;
	
// 	i = 0;
// 	while (i < OPERS_SIZE)
// 	{
// 		if (opers_hash[i])
// 		{
// 			data = get_hash_data(opers_hash, )
// 		}
// 	}
// }