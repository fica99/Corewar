# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara <aashara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 11:46:19 by olegmulko         #+#    #+#              #
#    Updated: 2020/10/17 22:57:13 by aashara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft := libft

libop := libop

libsocket := libsocket

libdraw := libdraw

.PHONY: all clean fclean $(libft) $(libop) $(libsocket) $(libdraw)

all: $(libft) $(libop) $(libsocket) $(libdraw)

$(libft):
	@$(MAKE) --no-print-directory -C $(libft)

$(libop):
	@$(MAKE) --no-print-directory -C $(libop)

$(libsocket):
	@$(MAKE) --no-print-directory -C $(libsocket)

$(libdraw):
	@$(MAKE) --no-print-directory -C $(libdraw)

clean:
	@$(MAKE) clean --no-print-directory -C  $(libft)
	@$(MAKE) clean --no-print-directory -C  $(libsocket)
	@$(MAKE) clean --no-print-directory -C  $(libop)
	@$(MAKE) clean --no-print-directory -C  $(libdraw)

fclean:
	@$(MAKE) fclean --no-print-directory -C  $(libft)
	@$(MAKE) fclean --no-print-directory -C  $(libsocket)
	@$(MAKE) fclean --no-print-directory -C  $(libop)
	@$(MAKE) fclean --no-print-directory -C  $(libdraw)

re: fclean all
