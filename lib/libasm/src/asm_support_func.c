/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_support_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:21:14 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/08 20:25:37 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	asm_add_null_in_bd(t_asm_bin_data *bin_data, int bytes)
{
	bin_data->add(bin_data, 0, 2 * bytes);
}
