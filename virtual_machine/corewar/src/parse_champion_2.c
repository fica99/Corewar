/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:52:51 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 16:56:17 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		copy_comment(t_player *player, int fd)
{
	char		*comment_champion;

	comment_champion = parse_str(fd, COMMENT_LENGTH);
	ft_strcpy(player->comment, comment_champion);
	free(comment_champion);
}

void		copy_name(t_player *player, int fd)
{
	char		*name_champion;

	name_champion = parse_str(fd, PROG_NAME_LENGTH);
	ft_strcpy(player->name, name_champion);
	free(name_champion);
}
