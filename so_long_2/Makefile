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

LIBFT = ./libft
FT_PRINTF = $(LIBFT)/ft_printf
MINILIBX = ./minilibx

CC = cc
CFLAGS = -Werror -Wall -Wextra -I $(INC_DIR) -I $(LIBFT) -I $(FT_PRINTF) -I $(MINILIBX) -I ./inc
LDFLAGS = -L $(LIBFT) -L $(FT_PRINTF) -L $(MINILIBX) -lftprintf -lft -lmlx -lX11 -lXext

SRC = dstr.c font.c game.c game_draw_map.c game_create.c images.c list.c main.c \
		map.c map_at.c map_read.c map_verifications.c map_verify_walls.c map_verify_way.c \
		util.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(MINILIBX)/libmlx.a $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIBFT)/libft.a:
	INCLUDE_DIR=$(PWD) make -C $(LIBFT) all

$(FT_PRINTF)/libftprintf.a:
	INCLUDE_DIR=$(PWD) make -C $(FT_PRINTF) all

$(MINILIBX)/libmlx.a:
	INCLUDE_DIR=$(PWD) make -C $(MINILIBX) all

clean:
	make -C $(LIBFT) clean
	make -C $(FT_PRINTF) clean
	make -C $(MINILIBX) clean
	-rm $(OBJ_DIR)/*.o $(NAME)

fclean: clean
	make -C $(LIBFT) fclean
	make -C $(FT_PRINTF) fclean
	make -C $(MINILIBX) clean

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re
