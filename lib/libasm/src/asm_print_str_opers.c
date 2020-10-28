/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_print_str_opers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:09:53 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/28 21:34:58 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	asm_print_str_filetostr(char *str)
{
	ft_putendl_fd(str, STDOUT_FILENO);
}

void	asm_print_opershash(t_hash **opers_hash)
{
	int			i;
	t_hash		*tmp;
	t_asm_oper	*data;
	char		*delim;
	
	i = -1;
	delim = "---------------------------------------";
	while (++i < OPERS_SIZE)
	{
		if (!opers_hash[i])
			continue ;
		tmp = opers_hash[i];
		while (tmp)
		{
			printf("%s\n", delim);
			data = (t_asm_oper *)tmp->data;
			printf("operation = %s\n", data->name);
			asm_print_opershash_data1(data);
			asm_print_opershash_data2(data);
			asm_print_opershash_data3(data);
			if (data->args_mask & ARG_TYPE)
				printf("carry changes\n");
			printf("\n");
			tmp = tmp->next;
		}
	}
}

void	asm_print_opershash_data1(t_asm_oper *data)
{
	if ((data->args_mask & ARG_1_ALL) || (data->args_mask & ARG_1_REG)
			|| (data->args_mask & ARG_1_DIR)
			|| (data->args_mask & ARG_1_IND))
	{
		printf("1st arg: ");
		if (data->args_mask & ARG_1_DIR)
			printf("T_DIR/");
		if (data->args_mask & ARG_1_REG)
			printf("T_REG/");
		if (data->args_mask & ARG_1_IND)
			printf("T_IND");
		printf("\n");
	}
}

void	asm_print_opershash_data2(t_asm_oper *data)
{
	if ((data->args_mask & ARG_2_ALL) || (data->args_mask & ARG_2_REG)
			|| (data->args_mask & ARG_2_DIR)
			|| (data->args_mask & ARG_2_IND))
	{
		printf("2nd arg: ");
		if (data->args_mask & ARG_2_DIR)
			printf("T_DIR/");
		if (data->args_mask & ARG_2_REG)
			printf("T_REG/");
		if (data->args_mask & ARG_2_IND)
			printf("T_IND");
		printf("\n");
	}
}

void	asm_print_opershash_data3(t_asm_oper *data)
{
	if ((data->args_mask & ARG_3_ALL) || (data->args_mask & ARG_3_REG)
			|| (data->args_mask & ARG_3_DIR)
			|| (data->args_mask & ARG_3_IND))
	{
		printf("3rd arg: ");
		if (data->args_mask & ARG_3_DIR)
			printf("T_DIR/");
		if (data->args_mask & ARG_3_REG)
			printf("T_REG/");
		if (data->args_mask & ARG_3_IND)
			printf("T_IND");
		printf("\n");
	}
}

