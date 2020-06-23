# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara <aashara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 11:46:19 by olegmulko         #+#    #+#              #
#    Updated: 2020/06/23 15:38:37 by aashara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft := libft

libop := libop

libasm := libasm

.PHONY: all clean fclean $(libft) $(libop) $(libasm)

all: $(libft) $(libop) $(libasm)

$(libft):
	@$(MAKE) --no-print-directory -C $(libft)

$(libop):
	@$(MAKE) --no-print-directory -C $(libop)

$(libasm):
	@$(MAKE) --no-print-directory -C $(libasm)

clean:
	@$(MAKE) clean --no-print-directory -C  $(libft)
	@$(MAKE) clean --no-print-directory -C  $(libop)
	@$(MAKE) clean --no-print-directory -C  $(libasm)

fclean:
	@$(MAKE) fclean --no-print-directory -C  $(libft)
	@$(MAKE) fclean --no-print-directory -C  $(libop)
	@$(MAKE) fclean --no-print-directory -C  $(libasm)

re: fclean all
