# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:57:06 by aashara-          #+#    #+#              #
#    Updated: 2020/06/28 21:09:53 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libdraw.a

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		src
HDR_DIR	=		includes
OBJ_DIR	=		obj
LIB_DIR =		..


# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		drawer.cpp

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  LIBFT  ------------------------------------------------------- #
LFT		=		libft.a
LFT_DIR	=		$(LIB_DIR)/libft
LHS_DIR	=		$(LFT_DIR)/includes

# ------------  LIBSOCKET  ------------------------------------------------------- #
LSOC		=		libsocket.a
LSOC_DIR	=		$(LIB_DIR)/libsocket
LSOC_HS_DIR	=	$(LSOC_DIR)/includes

# ------------  LIBOP  ------------------------------------------------------- #
LOP		=		libop.a
LOP_DIR	=		$(LIB_DIR)/libop
LOP_HS_DIR	=	$(LOP_DIR)/includes

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		g++
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra -std=c++1z
LFLGS	=		-L $(LFT_DIR) -lft -L $(LSOC_DIR) -lsocket -L $(LOP) -lop -lncurses
IFLGS	=		-I $(HDR_DIR) -I $(LHS_DIR) -I $(LSOC_HS_DIR) -I $(LOP_HS_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O3


# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

$(LSOC_DIR)/$(LSOC):
	$(MAKE) -C $(LSOC_DIR)

$(LFT_DIR)/$(LFT):
	$(MAKE) -C $(LFT_DIR)

$(LOP_DIR)/$(LOP):
	$(MAKE) -C $(LOP_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(LSOC_DIR)/$(LSOC) $(LOP_DIR)/$(LOP) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(MAKE) clean -C $(LFT_DIR)
	$(MAKE) clean -C $(LOP_DIR)
	$(MAKE) clean -C $(LSOC_DIR)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) clean -C $(LFT_DIR)
	$(MAKE) fclean -C $(LOP_DIR)
	$(MAKE) fclean -C $(LSOC_DIR)
	$(RM) $(NAME)

re: fclean all
