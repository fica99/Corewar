# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/14 13:42:05 by aashara           #+#    #+#              #
#    Updated: 2020/10/29 21:27:32 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

asm := assembler/asm

disasm := assembler/disasm

corewar := virtual_machine/corewar

visualizer := virtual_machine/visualizer

.PHONY: all asm disasm corewar visualizer clean fclean re

all: asm disasm corewar visualizer

asm:
	$(MAKE) all --no-print-directory -C $(asm)

disasm:
	$(MAKE) all --no-print-directory -C $(disasm)

corewar:
	$(MAKE) all --no-print-directory -C $(corewar)

visualizer:
	$(MAKE) all --no-print-directory -C $(visualizer)

clean:
	$(MAKE) clean --no-print-directory -C $(asm)
	$(MAKE) clean --no-print-directory -C $(disasm)
	$(MAKE) clean --no-print-directory -C $(corewar)
	$(MAKE) clean --no-print-directory -C $(visualizer)

fclean:
	$(MAKE) fclean --no-print-directory -C $(asm)
	$(MAKE) fclean --no-print-directory -C $(disasm)
	$(MAKE) fclean --no-print-directory -C $(corewar)
	$(MAKE) fclean --no-print-directory -C $(visualizer)

re: fclean all
