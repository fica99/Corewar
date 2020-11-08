# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/14 12:47:29 by aashara           #+#    #+#              #
#    Updated: 2020/11/07 16:34:28 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		../../asm

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
LOP		=		libop.a
LOP_DIR	=		$(LIB_DIR)/libop
LOP_HS_DIR	=	$(LOP_DIR)/includes

# ------------  LIBASM ------------------------------------------------------- #
LASM		=	libasm.a
LASM_DIR	=	$(LIB_DIR)/libasm
LASM_HS_DIR	=	$(LASM_DIR)/includes

# ------------  LIBHASH  ------------------------------------------------------- #
LHASH		=	libhash.a
LHASH_DIR	=	$(LIB_DIR)/libhash
LHASH_HS_DIR	=	$(LHASH_DIR)/includes

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		main.c \
				check_inprms.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
LFLGS	=		-L $(LASM_DIR) -lasm -L $(LFT_PRINTF_DIR) -lftprintf -L $(LHASH_DIR) -lhash -lm
IFLGS	=		-I $(HDR_DIR) -I $(LHS_PRINTF_DIR) -I $(LOP_HS_DIR) -I $(LASM_HS_DIR) -I $(LHASH_HS_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O0 -g

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: lib $(NAME)

lib:
	$(MAKE) -C $(LFT_PRINTF_DIR)

$(LFT_PRINTF_DIR)/$(LFT_PRINTF):
	$(MAKE) -C $(LFT_PRINTF_DIR)

$(LASM_DIR)/$(LASM):
	$(MAKE) -C $(LASM_DIR)

$(LHASH_DIR)/$(LHASH):
	$(MAKE) -C $(LHASH_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -g -O0 $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_PRINTF_DIR)/$(LFT_PRINTF) $(LASM_DIR)/$(LASM) $(LHASH_DIR)/$(LHASH) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLGS)

clean:
	$(MAKE) -C $(LFT_PRINTF_DIR) clean
	$(MAKE) -C $(LASM_DIR) clean
	$(MAKE) -C $(LHASH_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LFT_PRINTF_DIR) fclean
	$(MAKE) -C $(LASM_DIR) fclean
	$(MAKE) -C $(LHASH_DIR) fclean
	$(RM) $(NAME)

re: fclean all
