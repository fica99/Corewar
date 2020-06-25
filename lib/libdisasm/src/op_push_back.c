#include "g_op.h"

t_op	*op_list_new(uint8_t byte)
{
	t_op *new;

	new = xmalloc(sizeof(t_op));
	*new = g_op[byte - 1];
	return (new);
}

t_op	*op_push_back(t_op **lst, uint8_t byte)
{
	t_op *tmp;

	if (byte > OP_COUNT)
	{
		ft_putendl_fd("bad operation code", STDERR_FILENO);
		return (NULL);
	}
	tmp = *lst;
	if (!(*lst))
		return (*lst = op_list_new(byte));
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->next = op_list_new(byte));
}
