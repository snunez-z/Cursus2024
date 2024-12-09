# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 10:47:03 by snunez-z          #+#    #+#              #
#    Updated: 2024/12/10 12:00:14 by snunez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./include

LIBFT = ./libft
FT_PRINTF = $(LIBFT)/ft_printf

CC = cc
CFLAGS = -Werror -Wall -Wextra -I $(INC_DIR) -I $(LIBFT) -I $(FT_PRINTF)
LDFLAGS = -L $(LIBFT) -lft -L $(FT_PRINTF) -lftprintf

SRC = list_numbers.c \
      list_stack_push.c \
      move_count.c \
      movement_min_number.c \
      rotate_resverse.c \
      rotate.c \
      sort_stacks.c \
      su_atoi.c \
      swap.c \
      main.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)

$(FT_PRINTF)/libftprintf.a:
	$(MAKE) -C $(FT_PRINTF)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(FT_PRINTF) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(FT_PRINTF) fclean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

.PHONY: all clean fclean re
