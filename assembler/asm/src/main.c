/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 01:00:23 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/24 20:29:40 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int ac, char **av)
{
	t_asm_string	*asm_str;
	t_asm_token		*tokens;
	t_hash			**opers_hash;

	check_inprms(ac, av);
	asm_str = asm_file_to_str(av[1]);
	opers_hash = asm_get_opers_hash();
	tokens = asm_get_chain_tokens(asm_str);
	if (tokens->next == TT_EOF)
		asm_prog_error("the file is empty");
	return (0);
}
