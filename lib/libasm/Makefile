# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/12 10:32:40 by olegmulko         #+#    #+#              #
#    Updated: 2020/07/12 10:52:27 by olegmulko        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libasm.a

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		src
HDR_DIR	=		includes
OBJ_DIR	=		obj
LIB_DIR =		..

# ------------  LIBFT  ------------------------------------------------------- #
LFT		=		libft.a
LFT_DIR	=		$(LIB_DIR)/libft
LHS_DIR	=		$(LFT_DIR)/includes

# ------------  LIBOP  ------------------------------------------------------- #
LOP		=		libop.a
LOP_DIR	=		$(LIB_DIR)/libop
LOP_HS_DIR	=	$(LOP_DIR)/includes


# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		asm_error.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
LFLGS	=		-L $(LFT_DIR) -lft -L $(LOP_DIR) -lop
IFLGS	=		-I $(HDR_DIR) -I $(LHS_DIR) -I $(LOP_HS_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O3


# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

$(LFT_DIR)/$(LFT):
	$(MAKE) -C $(LFT_DIR)

$(LOP_DIR)/$(LOP):
	$(MAKE) -C $(LOP_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(LOP_DIR)/$(LOP) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(MAKE) clean -C $(LFT_DIR)
	$(MAKE) clean -C $(LOP_DIR)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LFT_DIR)
	$(MAKE) fclean -C $(LOP_DIR)
	$(RM) $(NAME)

re: fclean all
