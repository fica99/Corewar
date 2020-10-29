/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:18:04 by ggrimes           #+#    #+#             */
/*   Updated: 2020/08/19 16:45:07 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	pf_convert_nb(t_pf_mod_len mod, intmax_t num)
{
	if (mod == PF_ML_INIT)
		return ((int)num);
	else if (mod == PF_ML_H)
		return ((short)num);
	else if (mod == PF_ML_HH)
		return ((char)num);
	else if (mod == PF_ML_L)
		return ((long)num);
	else if (mod == PF_ML_LL)
		return ((long long)num);
	else if (mod == PF_ML_J || mod == PF_ML_T)
		return ((intmax_t)num);
	else if (mod == PF_ML_Z)
		return ((size_t)num);
	else
		return ((int)num);
}

intmax_t	pf_convert_unb(t_pf_mod_len mod, intmax_t num)
{
	if (mod == PF_ML_H)
		return ((unsigned short)num);
	else if (mod == PF_ML_HH)
		return ((unsigned char)num);
	else if (mod == PF_ML_L)
		return ((unsigned long)num);
	else if (mod == PF_ML_LL)
		return ((unsigned long long)num);
	else if (mod == PF_ML_J || mod == PF_ML_T)
		return ((uintmax_t)num);
	else if (mod == PF_ML_Z)
		return ((size_t)num);
	else
		return ((unsigned int)num);
}

size_t		pf_get_nb_size(t_pf_mod_len mod)
{
	if (mod == PF_ML_INIT)
		return (sizeof(int));
	else if (mod == PF_ML_H)
		return (sizeof(short));
	else if (mod == PF_ML_HH)
		return (sizeof(char));
	else if (mod == PF_ML_L)
		return (sizeof(long));
	else if (mod == PF_ML_LL)
		return (sizeof(long long));
	else if (mod == PF_ML_J || mod == PF_ML_T)
		return (sizeof(intmax_t));
	else if (mod == PF_ML_Z)
		return (sizeof(size_t));
	else
		return (sizeof(int));
}

size_t		pf_get_unb_size(t_pf_mod_len mod)
{
	if (mod == PF_ML_H)
		return (sizeof(unsigned short));
	else if (mod == PF_ML_HH)
		return (sizeof(unsigned char));
	else if (mod == PF_ML_L)
		return (sizeof(unsigned long));
	else if (mod == PF_ML_LL)
		return (sizeof(unsigned long long));
	else if (mod == PF_ML_J || mod == PF_ML_T)
		return (sizeof(uintmax_t));
	else if (mod == PF_ML_Z)
		return (sizeof(size_t));
	else
		return (sizeof(unsigned int));
}

char		*pf_get_bits(size_t size, void *ptr)
{
	unsigned char	*b;
	char			*str;
	int				i;
	int				j;
	int				k;

	if (!size || !ptr)
		return (NULL);
	if (!(str = ft_strnew(size * 8)))
		exit(EXIT_FAILURE);
	b = (unsigned char*)ptr;
	i = size;
	k = 0;
	while (--i >= 0)
	{
		j = 8;
		while (--j >= 0)
			str[k++] = ((b[i] >> j) & 1) ? '1' : '0';
	}
	return (str);
}
