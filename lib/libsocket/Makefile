# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:57:06 by aashara-          #+#    #+#              #
#    Updated: 2020/07/29 11:41:05 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libsocket.a

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
LOP_DIR	=		$(LIB_DIR)/libop
LOP_HS_DIR	=	$(LOP_DIR)/includes


# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		serialize.c\
				deserialize.c\
				send_data.c\

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
LFLGS	=		-L $(LFT_DIR) -lft
IFLGS	=		-I $(HDR_DIR) -I $(LHS_DIR) -I $(LOP_HS_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O0 -g


# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

$(LFT_DIR)/$(LFT):
	$(MAKE) -C $(LFT_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(MAKE) clean -C $(LFT_DIR)
	$(RM) $(OBJ_DIR)

fclean:
	$(MAKE) fclean -C $(LFT_DIR)
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all
