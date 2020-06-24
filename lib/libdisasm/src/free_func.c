#include "libdisasm.h"

void	free_buf(t_buf *buf)
{
	free(buf->bytes);
	free(buf);
}

void	free_op_list(t_op *lst)
{
	t_op *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	free_champ(t_champ *champ)
{
	free(champ->name);
	free(champ->comment);
	if (champ->exec_code)
		free_op_list(champ->exec_code);
	free(champ);
}
