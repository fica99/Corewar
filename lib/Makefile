# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 11:46:19 by olegmulko         #+#    #+#              #
#    Updated: 2020/10/27 18:51:31 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft := libft

libdraw := libserver

.PHONY: all clean fclean $(libft) $(libserver)

all: $(libft) $(libop) $(libsocket) $(libserver)

$(libft):
	@$(MAKE) --no-print-directory -C $(libft)

$(libserver):
	@$(MAKE) --no-print-directory -C $(libserver)

clean:
	@$(MAKE) clean --no-print-directory -C  $(libft)
	@$(MAKE) clean --no-print-directory -C  $(libserver)

fclean:
	@$(MAKE) fclean --no-print-directory -C  $(libft)
	@$(MAKE) fclean --no-print-directory -C  $(libserver)

re: fclean all
