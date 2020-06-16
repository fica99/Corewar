# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara <aashara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 11:46:19 by olegmulko         #+#    #+#              #
#    Updated: 2020/06/16 20:49:03 by aashara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft := libft

libop := libop

.PHONY: all clean fclean $(libft) $(libop)

all: $(libft) $(libop)

$(libft):
	@$(MAKE) --no-print-directory -C $(libft)

$(libop):
	@$(MAKE) --no-print-directory -C $(libop)

clean:
	@$(MAKE) clean --no-print-directory -C  $(libft)
	@$(MAKE) clean --no-print-directory -C  $(libop)

fclean:
	@$(MAKE) fclean --no-print-directory -C  $(libft)
	@$(MAKE) fclean --no-print-directory -C  $(libop)

re: fclean all
