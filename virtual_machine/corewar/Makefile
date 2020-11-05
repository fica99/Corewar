# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/14 12:47:29 by aashara           #+#    #+#              #
#    Updated: 2020/11/05 02:29:24 by kdeloise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		../../corewar

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		src
HDR_DIR	=		includes
OBJ_DIR	=		objs
LIB_DIR =		../../lib

# ------------  LIBFTPRINTF  ------------------------------------------------- #
LFT_PRINTF		=		libftprintf.a
LFT_PRINTF_DIR	=		$(LIB_DIR)/libftprintf
LHS_PRINTF_DIR	=		$(LFT_PRINTF_DIR)/includes

# ------------  LIBSERVER  ------------------------------------------------------- #
LSERVER		=	libserver.a
LSERVER_DIR	=	$(LIB_DIR)/libserver
LSERVER_HS_DIR	=	$(LSERVER_DIR)/includes

# ------------  LIBOP  ------------------------------------------------------- #
LOP_DIR		=		$(LIB_DIR)/libop
LOP_HS_DIR	=		$(LOP_DIR)/includes

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		additional.c check.c check_count_cor_files.c init.c main.c \
                op_add.c op_aff.c op_and.c op_fork.c op_ld.c op_ldi.c \
                op_lfork.c op_live.c op_lld.c op_lldi.c op_or.c op_st.c \
                op_sti.c op_sub.c op_xor.c op_zjmp.c parse_args.c \
                parse_champion.c run_vm.c validate.c calculate.c output.c fill_arena.c \
                vs_ip.c parse_cor_file.c is_int.c parse_champion_2.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
LFLGS	=		-L $(LFT_PRINTF_DIR) -lftprintf -L $(LSERVER_DIR) -lserver
IFLGS	=		-I $(HDR_DIR) -I $(LHS_PRINTF_DIR) -I $(LOP_HS_DIR) -I $(LSERVER_HS_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O0 -g

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: lib $(NAME)

lib:
	$(MAKE) -C $(LFT_PRINTF_DIR)
	$(MAKE) -C $(LSERVER_DIR)

$(LFT_PRINTF_DIR)/$(LFT_PRINTF):
	$(MAKE) -C $(LFT_PRINTF_DIR)

$(LSERVER_DIR)/$(LSERVER):
	$(MAKE) -C $(LSERVER_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_PRINTF_DIR)/$(LFT_PRINTF) $(LSERVER_DIR)/$(LSERVER) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLGS)

clean:
	$(MAKE) -C $(LFT_PRINTF_DIR) clean
	$(MAKE) -C $(LSERVER_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LFT_PRINTF_DIR) fclean
	$(MAKE) -C $(LSERVER_DIR) fclean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all
