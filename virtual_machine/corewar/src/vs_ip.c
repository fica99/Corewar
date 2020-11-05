/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_ip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:12:13 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 02:14:08 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int	ft_count_words(const char *s, int c)
{
	int			end_of_line;
	int			end_of_word;

	while (*s)
	{
		if (*s == 0)
			return (0);
		end_of_line = (*s != c && *(s + 1) == 0);
		end_of_word = (*s != c && *(s + 1) == c);
		if (end_of_line || end_of_word)
			return (1 + ft_count_words(++s, c));
		++s;
	}
	return (0);
}

t_bool		check_ip_split(char **ip_split)
{
	int		byte;

	while (*ip_split)
	{
		if ((byte = ft_atoi(*ip_split) < 0) || byte > 255 ||
			!(is_int(*ip_split)))
			return (False);
		ip_split++;
	}
	return (True);
}

t_bool		is_ip(char *ip)
{
	char	**ip_split;
	int		count_ip_split;

	count_ip_split = ft_count_words(ip, '.');
	if (count_ip_split == 4)
	{
		ip_split = ft_strsplit(ip, '.');
		return (check_ip_split(ip_split));
	}
	return (False);
}

void		parse_vs_flag(int *argc, char ***argv, t_vm *vm)
{
	if (!vm->vs && *argc >= 2 && is_ip(*(*argv + 1)) && vm->num_players)
	{
		vm->vs = True;
		vm->vs_ip = (*(*argv + 1));
		(*argc) -= 2;
		(*argv) += 2;
	}
	else
		help();
}
