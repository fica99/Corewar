# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara <aashara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/14 12:47:29 by aashara           #+#    #+#              #
#    Updated: 2020/06/23 22:48:13 by aashara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		../../disasm

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		src
HDR_DIR	=		includes
OBJ_DIR	=		obj
LIB_DIR =		../../lib

# ------------  LIBFT  ------------------------------------------------------- #
LFT		=		libft.a
LFT_DIR	=		$(LIB_DIR)/libft
LHS_DIR	=		$(LFT_DIR)/includes

# ------------  LIBOP  ------------------------------------------------------- #
LOP		=		libop.a
LOP_DIR	=		$(LIB_DIR)/libop
LOP_HS_DIR	=	$(LOP_DIR)/includes

# ------------  LIBDISASM ------------------------------------------------------- #
LDISASM		=		libdisasm.a
LDISASM_DIR	=		$(LIB_DIR)/libdisasm
LDISASM_HS_DIR	=		$(LDISASM_DIR)/includes

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		main.c print_op.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
LFLGS	=		-L $(LOP_DIR) -lop -L $(LDISASM_DIR) -ldisasm -L $(LFT_DIR) -lft 
IFLGS	=		-I $(HDR_DIR) -I $(LHS_DIR) -I $(LOP_HS_DIR) -I $(LDISASM_HS_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O3 -g

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

$(LFT_DIR)/$(LFT):
	$(MAKE) -C $(LFT_DIR)

$(LOP_DIR)/$(LOP):
	$(MAKE) -C $(LOP_DIR)

$(LDISASM_DIR)/$(LDISASM):
	$(MAKE) -C $(LDISASM_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(LOP_DIR)/$(LOP) $(LDISASM_DIR)/$(LDISASM) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLGS)

$(NAME): $(OBJS)

clean:
	$(MAKE) -C $(LFT_DIR) clean
	$(MAKE) -C $(LOP_DIR) clean
	$(MAKE) -C $(LDISASM_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LFT_DIR) fclean
	$(MAKE) -C $(LOP_DIR) fclean
	$(MAKE) -C $(LDISASM_DIR) fclean
	$(RM) $(NAME)

re: fclean all
