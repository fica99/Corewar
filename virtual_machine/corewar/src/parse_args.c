#include "corewar.h"

void		help()
{
	ft_printf("Usage: ./corewar [-dump <num>] [-v <ip>] "
	"[-n <num>] [-a] <champion.cor> <...>\n");
	exit(0);
}

t_player	*find_player(t_vm *vm, int id)
{
	int		i;

	i = 0;
	while (ft_strcmp(vm->players[i]->name, "\0") && i < MAX_PLAYERS)
	{
		if (id == vm->players[i]->id)
			return (vm->players[i]);
		i++;
	}
	return (NULL);
}

void		add_player(t_vm *vm, t_player *player)
{
	int		i;

	i = 0;
	while (ft_strcmp(vm->players[i]->name, "\0") && i < MAX_PLAYERS)
		i++;
	vm->players[i] = player;
}

void		update_players_id(t_vm *vm)
{
	int	i;
	int id;

	i = 0;
	id = 1;
	while (i < vm->num_players)
	{
		if (vm->players[i]->id == 0)
		{
			while (find_player(vm, id))
				id++;
			vm->players[i]->id = id;
		}
		i++;
	}
}

void		check_double_ids(t_vm *vm)
{
	t_player	*player[vm->num_players];
	int			id;
	int			i;

	i = 0;
	while(i < vm->num_players)
	{
		if (!(player[i] = (t_player *)malloc(sizeof(t_player))))
			ft_exit("Error malloc");
		i++;
	}
	i = 0;
	id = 1;
	while (i < vm->num_players)
	{
		if (!(player[i++] = find_player(vm, id++)))
			help();
	}
	i = 0;
	while (i < MAX_PLAYERS)
	{
		while (i >= vm->num_players && i < MAX_PLAYERS)
		{
			vm->players[i++] = NULL;
		}
		vm->players[i] = player[i];
		i++;
	}
	vm->last_alive = vm->players[vm->num_players - 1];
}

void		parse_cor_file(int *argc, char ***argv, t_vm *vm)
{
	int		id;

	id = 0;
	if (*argc >= 3 && !ft_strcmp(**argv, "-n"))
	{
		if (!is_int(*(*argv + 1))
			|| (id = atoi_check_int(*(*argv + 1))) < 1
			|| id > MAX_PLAYERS
			|| find_player(vm, id)
			|| !is_cor_file(*(*argv + 2)))
			help();
		parse_champion(*(*argv + 2), vm, id);
		add_player(vm, parse_champion(*(*argv + 2), vm, id));
		(*argc) -= 3;
		(*argv) += 3;
	}
	else if (is_cor_file(**argv))
	{
		parse_champion(**argv, vm, id);
		add_player(vm, parse_champion(**argv, vm, id));
		(*argc)--;
		(*argv)++;
	}
	else
		help();
}

void	parse_log_flag(int *argc, char ***argv, t_vm *vm)
{
	vm->logs = True;
	(*argc) -= 1;
	(*argv) += 1;
}

void	parse_dump_flag(int *argc, char ***argv, t_vm *vm)
{
	if (!vm->dump_print_mode && *argc >= 2 && is_int(*(*argv + 1)) && vm->num_players)
	{
		if ((vm->dump = ft_atoi(*(*argv + 1))) < 0)
			vm->dump = -1;
		if (!ft_strcmp(**argv, "-d"))
			vm->dump_print_mode = 64;
		else
			vm->dump_print_mode = 32;
		(*argc) -= 2;
		(*argv) += 2;
	}
	else
		help();
}

static	int		ft_count_words(const char *s, int c)
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

t_bool 		check_ip_split(char **ip_split)
{
	int		byte;

	while (*ip_split)
	{
		if ((byte = ft_atoi(*ip_split) < 0) || byte > 255 || !(is_int(*ip_split)))
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

void		parse_args(char **argv, int argc, t_vm *vm)
{
	while (argc >= 1)
	{
		if ((!ft_strcmp(*argv, "-n") || is_cor_file(*argv)))
			parse_cor_file(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-dump") || !ft_strcmp(*argv, "-d"))
			parse_dump_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-v"))
			parse_vs_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-l"))
			parse_log_flag(&argc, &argv, vm);
		else
			help();
	}
	if (vm->num_players < 1 || vm->num_players > MAX_PLAYERS)
		ft_exit("Error <Number of champions more then MAX_PLAYERS or less then 1>");
	update_players_id(vm);
	check_double_ids(vm);
}
