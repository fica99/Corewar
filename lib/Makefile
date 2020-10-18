# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara <aashara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 11:46:19 by olegmulko         #+#    #+#              #
#    Updated: 2020/10/18 18:57:44 by aashara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft := libft

libdraw := libdraw

.PHONY: all clean fclean $(libft) $(libdraw)

all: $(libft) $(libop) $(libsocket) $(libdraw)

$(libft):
	@$(MAKE) --no-print-directory -C $(libft)

$(libdraw):
	@$(MAKE) --no-print-directory -C $(libdraw)

clean:
	@$(MAKE) clean --no-print-directory -C  $(libft)
	@$(MAKE) clean --no-print-directory -C  $(libdraw)

fclean:
	@$(MAKE) fclean --no-print-directory -C  $(libft)
	@$(MAKE) fclean --no-print-directory -C  $(libdraw)

re: fclean all
