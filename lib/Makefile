# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 11:46:19 by olegmulko         #+#    #+#              #
#    Updated: 2020/10/28 21:07:01 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libftprintf := libftprintf

libdraw := libserver

.PHONY: all clean fclean $(libftprintf) $(libserver)

all: $(libftprintf) $(libop) $(libsocket) $(libserver)

$(libftprintf):
	@$(MAKE) --no-print-directory -C $(libftprintf)

$(libserver):
	@$(MAKE) --no-print-directory -C $(libserver)

clean:
	@$(MAKE) clean --no-print-directory -C  $(libftprintf)
	@$(MAKE) clean --no-print-directory -C  $(libserver)

fclean:
	@$(MAKE) fclean --no-print-directory -C  $(libftprintf)
	@$(MAKE) fclean --no-print-directory -C  $(libserver)

re: fclean all
