/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:24:25 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/19 22:05:49 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define STR_RED "{red}"
#define C_RED "\033[0;31m"
#define STR_LEN_RED 5
#define C_LEN_RED 7

#define STR_EOC "{eoc}"
#define STR_LEN_EOC 5
#define C_EOC "\033[0m"
#define C_LEN_EOC 4

#define STR_GREEN "{green}"
#define C_GREEN "\033[0;32m"
#define STR_LEN_GREEN 7
#define C_LEN_GREEN 7

#define STR_YELLOW "{yellow}"
#define C_YELLOW "\033[0;33m"
#define STR_LEN_YELLOW 8
#define C_LEN_YELLOW 7

#define STR_BLUE "{blue}"
#define C_BLUE "\033[0;34m"
#define STR_LEN_BLUE 6
#define C_LEN_BLUE 7

#define STR_PURPLE "{purple}"
#define C_PURPLE "\033[0;35m"
#define STR_LEN_PURPLE 8
#define C_LEN_PURPLE 7

#define STR_CYAN "{cyan}"
#define C_CYAN "\033[0;36m"
#define STR_LEN_CYAN 6
#define C_LEN_CYAN 7

static void	pf_add_color(t_printf *pf, char *color, const char *format,
																size_t len)
{
	pf_check_mem(pf, len);
	pf_add_str_2_buff(pf, color, len);
	pf->i = ft_strchr(format + pf->i, '}') - format + 1;
}

char		pf_parse_color(const char *format, t_printf *pf)
{
	if (ft_strnequ(format + pf->i, STR_RED, STR_LEN_RED))
		pf_add_color(pf, C_RED, format, C_LEN_RED);
	else if (ft_strnequ(format + pf->i, STR_EOC, STR_LEN_EOC))
		pf_add_color(pf, C_EOC, format, C_LEN_EOC);
	else if (ft_strnequ(format + pf->i, STR_GREEN, STR_LEN_GREEN))
		pf_add_color(pf, C_GREEN, format, C_LEN_GREEN);
	else if (ft_strnequ(format + pf->i, STR_YELLOW, STR_LEN_YELLOW))
		pf_add_color(pf, C_YELLOW, format, C_LEN_YELLOW);
	else if (ft_strnequ(format + pf->i, STR_BLUE, STR_LEN_BLUE))
		pf_add_color(pf, C_BLUE, format, C_LEN_BLUE);
	else if (ft_strnequ(format + pf->i, STR_PURPLE, STR_LEN_PURPLE))
		pf_add_color(pf, C_PURPLE, format, C_LEN_PURPLE);
	else if (ft_strnequ(format + pf->i, STR_CYAN, STR_LEN_CYAN))
		pf_add_color(pf, C_CYAN, format, C_LEN_CYAN);
	else
		return (FALSE);
	return (TRUE);
}
