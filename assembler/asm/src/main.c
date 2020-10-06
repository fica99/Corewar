/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 01:00:23 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/06 20:30:03 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int ac, char **av)
{
	t_asm_string	*asm_str;
	t_asm_token		*tokens;
	t_hash			**opers_hash;
	t_asm_bin_data	*bin_data;

	check_inprms(ac, av);
	asm_str = asm_file_to_str(av[1]);
	opers_hash = asm_get_opers_hash();
	tokens = asm_lex_get_chain_tokens(asm_str, opers_hash);
	if (tokens->next == TT_EOF)
		asm_prog_error("the file is empty");
	bin_data = asm_init_bin_data(BIN_DATA_SIZE);
	bin_data->add(bin_data, COREWAR_EXEC_MAGIC, 8);
	return (0);
}
