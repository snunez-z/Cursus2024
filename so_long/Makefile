# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 09:26:09 by snunez-z          #+#    #+#              #
#    Updated: 2024/10/04 09:26:15 by snunez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

PWD = $(shell pwd)
INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj

LIB = ./lib
LIBFT = ./libft
GET_NEXT_LINE = ./get_next_line
FT_PRINTF = ./ft_printf
MINILIBX = ./minilibx

CC = cc
CFLAGS = -Werror -Wall -Wextra -I $(INC_DIR) -I $(LIBFT) -I $(GET_NEXT_LINE) -I $(FT_PRINTF) -I $(MINILIBX) -I ./inc
LDFLAGS = -L $(LIB) -lftprintf -lft -lX11 -lXext -lmlx

SRC =	get_next_line.c get_next_line_utils.c \
		font.c game.c game_draw_map.c game_create.c images.c main.c \
		map.c map_at.c map_loop.c map_read.c \
		map_verifications.c map_verify_walls.c map_verify_way.c \
		util.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: create_dirs libs $(NAME)

create_dirs:
	-mkdir lib
	-mkdir obj

libs:
	INCLUDE_DIR=$(PWD) make -C $(LIBFT) bonus
	cp $(LIBFT)/libft.a $(LIB)
	INCLUDE_DIR=$(PWD) make -C $(FT_PRINTF) all
	cp $(FT_PRINTF)/libftprintf.a $(LIB)
	INCLUDE_DIR=$(PWD) make -C $(MINILIBX) all
	cp $(MINILIBX)/libmlx.a $(LIB)

clean:
	make -C $(LIBFT) clean
	make -C $(FT_PRINTF) clean
	make -C $(MINILIBX) clean
	-rm $(LIB)/* $(OBJ_DIR)/*.o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: get_next_line/%.c
	$(CC) $(CFLAGS) -c $< -o $@

