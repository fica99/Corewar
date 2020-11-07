/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 01:00:23 by aashara-          #+#    #+#             */
/*   Updated: 2020/11/07 17:48:27 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			file_forming(char *av,
	t_asm_bin_data *bin_data)
{
	t_asm_file		*file;

	file = asm_file_init(av, "cor");
	file->open(file, O_CREAT | O_TRUNC | O_WRONLY, S_IREAD | S_IWRITE);
	file->write_bin_data(file, bin_data);
	free(file->name);
	free(file->exp);
	free(file);
	return (0);
}

int					main(int ac, char **av)
{
	t_asm_string	*asm_str;
	t_hash			**opers_hash;
	t_asm_token		*tokens;
	t_asm_bin_data	*bin_data;
	t_asm_pars_prms	*prms;

	check_inprms(ac, av);
	asm_str = asm_file_to_str(av[1]);
	opers_hash = asm_get_opers_hash();
	tokens = asm_lex_get_chain_tokens(asm_str, opers_hash);
	if (tokens->type == TT_EOF)
		asm_prog_error("the file is empty");
	tokens = asm_lex_del_all_com_tokens(tokens);
	bin_data = asm_init_bin_data(BIN_DATA_SIZE);
	prms = asm_init_pars_prms();
	if (asm_parser(tokens, bin_data, prms) == -1)
		asm_pars_error(prms);
	file_forming(av[1], bin_data);
	exit(0);
}
