# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 09:26:09 by snunez-z          #+#    #+#              #
#    Updated: 2024/11/07 17:35:08 by snunez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

PWD = $(shell pwd)
INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ./lib

LIB = ./lib
LIBFT = ./libft
FT_PRINTF = $(LIBFT)/ft_printf
MINILIBX = ./minilibx

CC = cc
CFLAGS = -Werror -Wall -Wextra -I $(INC_DIR) -I $(LIBFT) -I $(FT_PRINTF) -I $(MINILIBX) -I ./inc
LDFLAGS = -L $(LIB_DIR) -lftprintf -lft -lmlx -lX11 -lXext

SRC = dstr.c font.c game.c game_draw_map.c game_create.c images.c list.c main.c \
		map.c map_at.c map_read.c map_verifications.c map_verify_walls.c map_verify_way.c \
		util.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(LIB_DIR)/libft.a $(LIB_DIR)/libftprintf.a $(LIB_DIR)/libmlx.a $(NAME)

$(LIB_DIR):
	mkdir $(LIB_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIBFT)/libft.a:
	INCLUDE_DIR=$(PWD) make -C $(LIBFT) all

$(FT_PRINTF)/libftprintf.a:
	INCLUDE_DIR=$(PWD) make -C $(FT_PRINTF) all

$(MINILIBX)/libmlx.a:
	INCLUDE_DIR=$(PWD) make -C $(MINILIBX) all

$(LIB_DIR)/libft.a: $(LIB_DIR) $(LIBFT)/libft.a
	cp $(LIBFT)/libft.a $@

$(LIB_DIR)/libftprintf.a: $(LIB_DIR) $(FT_PRINTF)/libftprintf.a
	cp $(FT_PRINTF)/libftprintf.a $@

$(LIB_DIR)/libmlx.a: $(LIB_DIR) $(MINILIBX)/libmlx.a
	cp $(MINILIBX)/libmlx.a $@

clean:
	make -C $(LIBFT) clean
	make -C $(FT_PRINTF) clean
	make -C $(MINILIBX) clean
	-rm $(LIB_DIR)/* $(OBJ_DIR)/*.o $(NAME)
	-rmdir $(LIB_DIR)

fclean: clean
	make -C $(LIBFT) fclean
	make -C $(FT_PRINTF) fclean
	make -C $(MINILIBX) clean
	-rm -rf $(LIB_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re