/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 23:36:02 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 23:07:43 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				pf_init_start(t_printf *pf)
{
	ft_bzero(pf, sizeof(*pf));
	pf->malloc_len = PRINTF_BUFF_SIZE;
	if (!(pf->buff = (char*)malloc(pf->malloc_len * sizeof(char))))
		exit(1);
}

int					ft_dprintf(int fd, const char *format, ...)
{
	t_printf		pf;
	size_t			res;

	if (!format)
		return (0);
	pf_init_start(&pf);
	va_start(pf.argptr, format);
	while (format[pf.i])
		pf_parse_string(format, &pf);
	res = write(fd, pf.buff, pf.buff_len);
	va_end(pf.argptr);
	ft_strdel(&pf.buff);
	return (res);
}
