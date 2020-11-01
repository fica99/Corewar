#include "corewar.h"

void	output_arena(unsigned char *arena, int print_mode)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.4p : ", i);
		j = 0;
		while (j < print_mode)
		{
			ft_printf("%.2x ", arena[i + j]);
			j++;
		}
		ft_printf("\n");
		i += print_mode;
	}
}

void	dump_output(t_vm *vm)
{
	if (vm->dump == vm->cycle)
	{
		output_arena(vm->arena, vm->dump_print_mode);
		exit(0);
	}
}