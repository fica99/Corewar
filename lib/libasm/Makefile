# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara <aashara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/14 12:47:29 by aashara           #+#    #+#              #
#    Updated: 2020/06/23 15:43:22 by aashara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		libasm.a

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		src
HDR_DIR	=		includes
OBJ_DIR	=		obj
LIB_DIR =		../../lib

# ------------  LIBFT  ------------------------------------------------------- #
LFT		=		libft.a
LFT_DIR	=		$(LIB_DIR)/libft
LHS_DIR	=		$(LFT_DIR)/includes

# ------------  OP     ------------------------------------------------------- #
LOP		=		libop.a
LOP_DIR	=		$(LIB_DIR)/libop
LOPH_DIR	=	$(LOP_DIR)/includes

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		main.c err.c convert_bytes.c free_func.c \
				parse_champ.c util.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(OBJ_DIR)/*.o#$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS)) $(OBJ_DIR)/*.o
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc -g
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
LFLGS	=		-L $(LFT_DIR) -lft -L $(LOP_DIR) -lop
IFLGS	=		-I $(HDR_DIR) -I $(LHS_DIR) -I $(LOPH_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O3

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re


all: $(NAME)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	ar --output $(OBJ_DIR) -x $(LFT_DIR)/libft.a
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#.PHONY: all clean fclean re

#all: $(NAME)
#
#$(LFT_DIR)/$(LFT):
#	$(MAKE) -C $(LFT_DIR)
#
#$(LOP_DIR)/$(LOP):
#	$(MAKE) -C $(LOP_DIR)
#
#-include $(DEPS)
#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
#	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)
#
#$(OBJ_DIR):
#	mkdir -p $(OBJ_DIR)
#
#$(NAME): $(LFT_DIR)/$(LFT) $(LOP_DIR)/$(LOP) $(OBJS)
#	$(CC) -o $(NAME) $(OBJS) $(LFLGS)
#
#$(NAME): $(OBJS)
#
#clean:
#	$(MAKE) -C $(LFT_DIR) clean
#	$(RM) $(OBJ_DIR)
#
#fclean: clean
#	$(MAKE) -C $(LFT_DIR) fclean
#	$(RM) $(NAME)
#
#re: fclean all
