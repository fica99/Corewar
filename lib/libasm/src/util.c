#include "disasm.h"

void	*xmalloc(size_t size)
{
	void *ptr;

	if (!(ptr = ft_memalloc(size)))
		fatal_error(strerror(errno));
	return (ptr);
}
