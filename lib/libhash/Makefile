# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 13:54:22 by aashara-          #+#    #+#              #
#    Updated: 2020/11/02 22:03:19 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		libhash.a

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		srcs
HDR_DIR	=		includes
OBJ_DIR	=		objs
LIB_DIR =		..

# ------------  LIBFTPRINTF  ------------------------------------------------- #
LFT_PRINTF		=	libftprintf.a
LFT_PRINTF_DIR	=	$(LIB_DIR)/libftprintf
LHS_PRINTF_DIR	=	$(LFT_PRINTF_DIR)/includes

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		free_hash_table.c\
				init_hash_table.c\
				init_hash.c\
				hash_index.c\
				djb2_hash_function.c\
				push_hash.c\
				get_hash_data.c\

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
LFLAGS	=		-L $(LFT_PRINTF_DIR) -lftprintf
IFLGS	=		-I $(HDR_DIR) -I $(LHS_PRINTF_DIR)
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
