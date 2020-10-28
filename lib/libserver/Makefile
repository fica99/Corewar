# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:57:06 by aashara-          #+#    #+#              #
#    Updated: 2020/10/28 21:24:29 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libserver.a

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		src
HDR_DIR	=		includes
OBJ_DIR	=		obj
LIB_DIR =		..


# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		connect.c\
				send_arena.c\
				serialize.c\
				deserialize.c\
				create_server.c\
				receive_arena.c


# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  LIBFTPRINTF  ------------------------------------------------- #
LFT_PRINTF		=	libftprintf.a
LFT_PRINTF_DIR	=	$(LIB_DIR)/libftprintf
LHS_PRINTF_DIR	=	$(LFT_PRINTF_DIR)/includes

# ------------  LIBOP  ------------------------------------------------------- #
LOP_DIR	=		$(LIB_DIR)/libop
LOP_HS_DIR	=	$(LOP_DIR)/includes

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Wextra -Werror
LFLGS	=		-L $(LFT_PRINTF_DIR) -lftprintf
IFLGS	=		-I $(HDR_DIR) -I $(LHS_PRINTF_DIR) -I $(LOP_HS_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O0 -g


# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

$(LFT_PRINTF_DIR)/$(LFT_PRINTF):
	$(MAKE) -C $(LFT_PRINTF_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_PRINTF_DIR)/$(LFT_PRINTF) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(MAKE) clean -C $(LFT_PRINTF_DIR)
	$(RM) $(OBJ_DIR)

fclean:
	$(MAKE) fclean -C $(LFT_PRINTF_DIR)
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all
