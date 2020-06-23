# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara <aashara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 11:46:19 by olegmulko         #+#    #+#              #
#    Updated: 2020/06/23 22:21:27 by aashara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft := libft

libop := libop

libdisasm := libdisasm

.PHONY: all clean fclean $(libft) $(libop) $(libdisasm)

all: $(libft) $(libop) $(libdisasm)

$(libft):
	@$(MAKE) --no-print-directory -C $(libft)

$(libop):
	@$(MAKE) --no-print-directory -C $(libop)

$(libdisasm):
	@$(MAKE) --no-print-directory -C $(libdisasm)

clean:
	@$(MAKE) clean --no-print-directory -C  $(libft)
	@$(MAKE) clean --no-print-directory -C  $(libop)
	@$(MAKE) clean --no-print-directory -C  $(libdisasm)

fclean:
	@$(MAKE) fclean --no-print-directory -C  $(libft)
	@$(MAKE) fclean --no-print-directory -C  $(libop)
	@$(MAKE) fclean --no-print-directory -C  $(libdisasm)

re: fclean all
