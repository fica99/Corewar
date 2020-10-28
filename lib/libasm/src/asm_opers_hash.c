/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_opers_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:49:56 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 21:54:44 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static t_asm_oper	*asm_init_oper(char *name, char code, int mask)
{
	t_asm_oper		*oper;

	if (!(oper = (t_asm_oper *)malloc(sizeof(t_asm_oper))))
		asm_sys_error();
	if (!(oper->name = ft_strdup(name)))
		asm_sys_error();
	oper->code = code;
	oper->args_mask = mask;
	return (oper);
}

static t_hash		**asm_get_opers_hash_next(t_hash **opers_hash)
{
	t_asm_oper		*oper;

	oper = NULL;
	oper = asm_init_oper("ldi", 0x0a, ARG_1_ALL | (ARG_2_ALL & ~ARG_2_IND) | ARG_3_REG);
	push_hash(opers_hash, "ldi", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("sti", 0x0b, ARG_1_REG | ARG_2_ALL | (ARG_3_ALL & ~ARG_3_IND));
	push_hash(opers_hash, "sti", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("fork", 0x0c, ARG_1_DIR);
	push_hash(opers_hash, "fork", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("lld", 0x0d, (ARG_1_ALL & ~ARG_1_REG) | ARG_2_REG | ARG_TYPE);
	push_hash(opers_hash, "lld", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("lldi", 0x0e, ARG_1_ALL | (ARG_2_ALL & ~ARG_2_IND)
		| ARG_3_REG | ARG_TYPE);
	push_hash(opers_hash, "lldi", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("lfork", 0x0f, ARG_1_DIR);
	push_hash(opers_hash, "lfork", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("aff", 0x10, ARG_1_REG);
	push_hash(opers_hash, "aff", (void *)oper, OPERS_SIZE);
	return (opers_hash);
}

t_hash				**asm_get_opers_hash(void)
{
	t_hash			**opers_hash;
	t_asm_oper		*oper;

	oper = NULL;
	if (!(opers_hash = init_hash_table(OPERS_SIZE)))
		asm_sys_error();
	oper = asm_init_oper("live", 0x01, ARG_1_DIR);
	push_hash(opers_hash, "live", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("ld", 0x02, ARG_1_DIR | ARG_1_IND | ARG_2_REG | ARG_TYPE);
	push_hash(opers_hash, "ld", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("st", 0x03, ARG_1_REG | ARG_2_REG | ARG_2_IND);
	push_hash(opers_hash, "st", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("add", 0x04, ARG_1_REG | ARG_2_REG | ARG_3_REG | ARG_TYPE);
	push_hash(opers_hash, "add", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("sub", 0x05, ARG_1_REG | ARG_2_REG | ARG_3_REG | ARG_TYPE);
	push_hash(opers_hash, "sub", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("and", 0x06, ARG_1_ALL | ARG_2_ALL | ARG_3_REG | ARG_TYPE);
	push_hash(opers_hash, "and", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("or", 0x07, ARG_1_ALL | ARG_2_ALL | ARG_3_REG | ARG_TYPE);
	push_hash(opers_hash, "or", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("xor", 0x08, ARG_1_ALL | ARG_2_ALL | ARG_3_REG | ARG_TYPE);
	push_hash(opers_hash, "xor", (void *)oper, OPERS_SIZE);
	oper = asm_init_oper("zjmp", 0x09, ARG_1_DIR);
		push_hash(opers_hash, "zjmp", (void *)oper, OPERS_SIZE);
	return (asm_get_opers_hash_next(opers_hash));
}
