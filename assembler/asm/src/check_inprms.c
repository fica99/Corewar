/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inprms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 10:47:02 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/13 21:45:06 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_ext_file(char *file_name)
{
	char	*pos;

	if (!(pos = ft_strrchr(file_name, '.')))
		return (0);
	if (ft_strcmp(pos + 1, "s") != 0)
		return (0);
	return (1);
}

void		check_inprms(int ac, char **av)
{
	if (ac != 2)
		asm_prog_error(ERR_INPUT_PARAMS);
	if (!check_ext_file(av[1]))
		asm_prog_error(ERR_FILE_EXT);
}
