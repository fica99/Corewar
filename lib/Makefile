# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 11:46:19 by olegmulko         #+#    #+#              #
#    Updated: 2020/09/29 20:53:23 by ggrimes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft := libft

libdisasm := libdisasm

libsocket := libsocket

libdraw := libdraw

.PHONY: all clean fclean $(libft) $(libsocket) $(libdisasm) $(libdraw)

all: $(libft) $(libsocket) $(libdisasm) $(libdraw)

$(libft):
	@$(MAKE) --no-print-directory -C $(libft)

$(libdisasm):
	@$(MAKE) --no-print-directory -C $(libdisasm)

$(libsocket):
	@$(MAKE) --no-print-directory -C $(libsocket)

$(libdraw):
	@$(MAKE) --no-print-directory -C $(libdraw)

clean:
	@$(MAKE) clean --no-print-directory -C  $(libft)
	@$(MAKE) clean --no-print-directory -C  $(libsocket)
	@$(MAKE) clean --no-print-directory -C  $(libdraw)
	@$(MAKE) clean --no-print-directory -C  $(libdisasm)

fclean:
	@$(MAKE) fclean --no-print-directory -C  $(libft)
	@$(MAKE) fclean --no-print-directory -C  $(libsocket)
	@$(MAKE) fclean --no-print-directory -C  $(libdisasm)
	@$(MAKE) clean --no-print-directory -C  $(libdisasm)

re: fclean all
