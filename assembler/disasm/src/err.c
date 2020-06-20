#include "libft.h"

void	fatal_error(char *mes)
{
	if (mes)
	{
		ft_putstr_fd("disasm: ", STDERR_FILENO);
		ft_putendl_fd(mes, STDERR_FILENO);
	}
	exit (1);
}
