/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 01:00:23 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/20 10:56:54 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int ac, char **av)
{
	t_asm_string	*asm_str;
	t_asm_token		*token;

	check_inprms(ac, av);
	asm_str = asm_file_to_str(av[1]);
	token = asm_get_token(asm_str);
	ft_putendl_fd((char*)token->data, STDOUT_FILENO);
	ft_putendl_fd(asm_str->str, STDOUT_FILENO);
	return (0);
}
