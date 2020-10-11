# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/12 10:32:40 by olegmulko         #+#    #+#              #
#    Updated: 2020/10/11 15:21:09 by ggrimes          ###   ########.fr        #
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

# ------------  LIBHASH  ------------------------------------------------------- #
LHASH		=	libhash.a
LHASH_DIR	=	$(LIB_DIR)/libhash
LHASH_HS_DIR	=	$(LHASH_DIR)/includes

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		asm_error.c\
				asm_filetostr.c\
				asm_new_str.c\
				asm_str_realoc.c\
				asm_lex_token.c\
				asm_lex_get_token.c\
				asm_lex_token_comment.c\
				asm_ltoa.c\
				asm_lex_chain_tokens.c\
				asm_lex_token_nl.c\
				asm_lex_token_str.c\
				asm_lex_token_chn.c\
				asm_lex_token_chcom.c\
				asm_lex_token_sep.c\
				asm_lex_token_label.c\
				asm_lex_token_arg_reg.c\
				asm_lex_token_arg_dir.c\
				asm_lex_token_arg_ind.c\
				asm_opers_hash.c\
				asm_lex_opers.c\
				asm_lex_arg_sep.c\
				asm_bin_data.c\
				asm_file.c\
				asm_parser.c\
				asm_pars_ch_name.c\
				asm_pars_sep.c\
				asm_pars_exec_code.c\
				asm_pars_ch_com.c\
				asm_support_func.c\
				asm_pars_error.c\

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
LFLGS	=		-L $(LFT_DIR) -lft -L $(LHASH_DIR) -lhash
IFLGS	=		-I $(HDR_DIR) -I $(LHS_DIR) -I $(LOP_HS_DIR) -I $(LHASH_HS_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O0


# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

$(LFT_DIR)/$(LFT):
	$(MAKE) -C $(LFT_DIR)

$(LHASH_DIR)/$(LHASH):
	$(MAKE) -C $(LHASH_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -g -O0 $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(LHASH_DIR)/$(LHASH) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(MAKE) clean -C $(LFT_DIR)
	$(MAKE) clean -C $(LHASH_DIR)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LFT_DIR)
	$(MAKE) fclean -C $(LHASH_DIR)
	$(RM) $(NAME)

re: fclean all
