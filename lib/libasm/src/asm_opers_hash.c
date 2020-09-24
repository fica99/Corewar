/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_opers_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:49:56 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/24 20:24:11 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libasm.h"

static t_asm_oper	*asm_init_oper(char *name, void (*f)(void))
{
	t_asm_oper		*oper;

	if (!(oper = (t_asm_oper *)malloc(sizeof(t_asm_oper))))
		asm_sys_error();
	if (!(oper->name	= ft_strdup(name)))
		asm_sys_error();
	oper->f = f;
	return (oper);
}

static t_hash	**asm_get_opers_hash_next(t_hash **opers_hash)
{
	t_asm_oper	*oper;

	oper = NULL;
	push_hash(opers_hash, "zjmp", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("ldi", NULL);
	push_hash(opers_hash, "ldi", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("sti", NULL);
	push_hash(opers_hash, "sti", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("fork", NULL);
	push_hash(opers_hash, "fork", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("lld", NULL);
	push_hash(opers_hash, "lld", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("lldi", NULL);
	push_hash(opers_hash, "lldi", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("lfork", NULL);
	push_hash(opers_hash, "lfork", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("aff", NULL);
	push_hash(opers_hash, "aff", (void *)oper, OPERS_SIZE);
	return (opers_hash);
}

t_hash			**asm_get_opers_hash()
{
	t_hash		**opers_hash;
	t_asm_oper	*oper;

	oper = NULL;
	if (!(opers_hash = init_hash_table(OPERS_SIZE)))
		asm_sys_error();
	oper = asm_init_oper("live", NULL);
	push_hash(opers_hash, "live", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("ld", NULL);
	push_hash(opers_hash, "ld", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("st", NULL);
	push_hash(opers_hash, "st", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("add", NULL);
	push_hash(opers_hash, "add", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("sub", NULL);
	push_hash(opers_hash, "sub", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("and", NULL);
	push_hash(opers_hash, "and", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("or", NULL);
	push_hash(opers_hash, "or", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("xor", NULL);
	push_hash(opers_hash, "xor", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("zjmp", NULL);
	return (asm_get_opers_hash_next(opers_hash));
}
