#include "libdisasm.h"

void	file_error(const char *fname, const char *mes)
{
	ft_putstr_fd("disasm: ", STDERR_FILENO);
	ft_putstr_fd(fname, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(mes, STDERR_FILENO);
}

void	fatal_error(const char *mes)
{
	if (mes)
	{
		ft_putstr_fd("disasm: ", STDERR_FILENO);
		ft_putendl_fd(mes, STDERR_FILENO);
	}
	exit(1);
}
