# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/14 12:47:29 by aashara           #+#    #+#              #
#    Updated: 2020/07/29 14:11:28 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		../../visualizer

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		src
HDR_DIR	=		includes
OBJ_DIR	=		obj
LIB_DIR =		../../lib

# ------------  LIBOP  ------------------------------------------------------- #
LOP_DIR	=		$(LIB_DIR)/libop
LOP_HS_DIR	=	$(LOP_DIR)/includes

# ------------  LIBSOCKET  ------------------------------------------------------- #
LSOC		=	libsocket.a
LSOC_DIR	=	$(LIB_DIR)/libsocket
LSOC_HS_DIR	=	$(LSOC_DIR)/includes

# ------------  LIBDRAW  ------------------------------------------------------- #
LDRAW		=	libdraw.a
LDRAW_DIR	=	$(LIB_DIR)/libdraw
LDRAW_HS_DIR	=	$(LDRAW_DIR)/includes

# ------------  LIBFT  ------------------------------------------------------- #
LFT		=		libft.a
LFT_DIR	=		$(LIB_DIR)/libft
LHS_DIR	=		$(LFT_DIR)/includes


# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		main.cpp\

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		g++
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra -std=c++1z
LFLGS	=		-L $(LSOC_DIR) -lsocket -L $(LFT_DIR) -lft -L $(LDRAW_DIR) -ldraw -lncurses
IFLGS	=		-I $(LOP_HS_DIR) -I $(LSOC_HS_DIR) -I $(LHS_DIR) -I $(LDRAW_HS_DIR) -I $(HDR_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O3

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

$(LFT_DIR)/$(LFT):
	$(MAKE) -C $(LFT_DIR)

$(LSOC_DIR)/$(LSOC):
	$(MAKE) -C $(LSOC_DIR)

$(LDRAW_DIR)/$(LDRAW):
	$(MAKE) -C $(LDRAW_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(LSOC_DIR)/$(LSOC) $(LDRAW_DIR)/$(LDRAW) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLGS)

$(NAME): $(OBJS)

clean:
	$(MAKE) -C $(LFT_DIR) clean
	$(MAKE) -C $(LSOC_DIR) clean
	$(MAKE) -C $(LDRAW_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LFT_DIR) fclean
	$(MAKE) -C $(LSOC_DIR) fclean
	$(MAKE) -C $(LDRAW_DIR) fclean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all
