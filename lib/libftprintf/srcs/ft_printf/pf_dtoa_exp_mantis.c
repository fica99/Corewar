/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoa_exp_mantis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:25:20 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/12 20:08:31 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_handle_before_coma(short exp, t_list **before_coma)
{
	static short	prev_exp;
	char			*content;
	t_list			*el;
	static t_list	*last;

	if (!*before_coma)
		last = NULL;
	if (!*before_coma || (prev_exp - exp) > exp)
		content = pf_pow(2, exp);
	else
		content = pf_div_pow(last->content, prev_exp, exp, 2);
	el = ft_lstnew(content, log10(2) * exp + 1);
	pf_add_elem2list(FALSE, last ? &last : before_coma, el);
	last = el;
	prev_exp = exp;
}

static void			pf_handle_active_bite(short exp, t_list **before_coma,
														t_list **after_coma)
{
	char			*content;
	t_list			*el;

	if (exp >= 0)
		pf_handle_before_coma(exp, before_coma);
	else
	{
		content = pf_pow(2, exp);
		exp = ft_abs(exp);
		el = ft_lstnew(content, log10(5) * exp + 1 + (int)(log10(2) * exp));
		pf_add_elem2list(TRUE, after_coma, el);
	}
}

static void			pf_sum_pows(t_list *head, char is_after_coma)
{
	t_list			*tmp;
	int				head_size;
	int				tmp_size;
	unsigned char	*content;
	unsigned char	*tmp_content;

	if (!head)
		return ;
	tmp = head;
	content = head->content;
	while ((tmp = tmp->next))
	{
		head_size = head->content_size;
		tmp_size = tmp->content_size;
		tmp_content = tmp->content;
		while (--tmp_size >= 0)
		{
			if (is_after_coma)
				content[tmp->content_size - (tmp_size + 1)] +=
					tmp_content[tmp->content_size - (tmp_size + 1)];
			else
				content[--head_size] += tmp_content[tmp_size];
		}
		pf_carry(head->content, head->content_size, FALSE);
	}
}

static void			pf_sum_lists2str(char *str, t_list *before_coma,
												t_list *after_coma)
{
	pf_sum_pows(before_coma, FALSE);
	pf_sum_pows(after_coma, TRUE);
	pf_dig_overflow((char**)&before_coma->content, 0,
									&before_coma->content_size, FALSE);
	str = pf_update_nums2str(str, before_coma);
	*(str++) = '.';
	str = pf_update_nums2str(str, after_coma);
	*str = '\0';
}

void				pf_exp_mantis2str(char *str, short exp,
										unsigned long mantis)
{
	int8_t			i;
	int8_t			j;
	t_list			*before_coma;
	t_list			*after_coma;
	unsigned char	*num;

	i = -1;
	num = (unsigned char*)&mantis;
	before_coma = NULL;
	after_coma = NULL;
	while (++i < 8)
	{
		j = 8;
		while (--j >= 0)
		{
			if (num[i] & (1 << j))
				pf_handle_active_bite(exp, &before_coma, &after_coma);
			--exp;
		}
	}
	pf_sum_lists2str(str, before_coma, after_coma);
	ft_lstdel(&before_coma, NULL);
	ft_lstdel(&after_coma, NULL);
}
