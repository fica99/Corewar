# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara <aashara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 11:46:19 by olegmulko         #+#    #+#              #
#    Updated: 2020/06/13 18:19:39 by aashara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft := libft

.PHONY: all clean fclean $(libft)

all: $(libft)

$(libft):
	@$(MAKE) --no-print-directory -C $(libft)
clean:
	@$(MAKE) clean --no-print-directory -C  $(libft)

fclean:
	@$(MAKE) fclean --no-print-directory -C  $(libft)

re: fclean all
