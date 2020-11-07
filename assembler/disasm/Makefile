# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/14 12:47:29 by aashara           #+#    #+#              #
#    Updated: 2020/11/07 16:34:34 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		../../disasm

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		src
HDR_DIR	=		includes
OBJ_DIR	=		objs
LIB_DIR =		../../lib

# ------------  LIBFTPRINTF  ------------------------------------------------- #
LFT_PRINTF		=		libftprintf.a
LFT_PRINTF_DIR	=		$(LIB_DIR)/libftprintf
LHS_PRINTF_DIR	=		$(LFT_PRINTF_DIR)/includes

# ------------  LIBOP  ------------------------------------------------------- #
LOP_DIR	=		$(LIB_DIR)/libop
LOP_HS_DIR	=	$(LOP_DIR)/includes


# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		main.c \
				print_op.c \
				parse.c \
				err.c \
				convert_bytes.c \
				free_func.c \
				parse_champ.c \
				util.c \
				op_push_back.c \
				fill_op.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
LFLGS	=		-L $(LFT_PRINTF_DIR) -lftprintf
IFLGS	=		-I $(HDR_DIR) -I $(LHS_PRINTF_DIR) -I $(LOP_HS_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O0 -g

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: lib $(NAME)

$(LFT_PRINTF_DIR)/$(LFT_PRINTF):
	$(MAKE) -C $(LFT_PRINTF_DIR)

lib:
	$(MAKE) -C $(LFT_PRINTF_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_PRINTF_DIR)/$(LFT_PRINTF) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLGS)

clean:
	$(MAKE) -C $(LFT_PRINTF_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LFT_PRINTF_DIR) fclean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)


re: fclean all
