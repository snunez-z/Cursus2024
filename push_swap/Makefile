# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 10:47:03 by snunez-z          #+#    #+#              #
#    Updated: 2024/12/19 13:23:39 by snunez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

PDW=$(shell pwd)
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./include
BONUS_DIR = ./bonus

LIBFT = ./libft
FT_PRINTF = $(LIBFT)/ft_printf

CC = cc
CFLAGS = -Werror -Wall -Wextra -I $(INC_DIR) -I $(LIBFT) -I $(FT_PRINTF)
LDFLAGS = -L $(LIBFT) -L $(FT_PRINTF) -lftprintf -lft

SRC_COMMON = list_numbers.c \
	list_stack_push.c \
	rotate_reverse.c \
	rotate.c \
	swap.c \
	is_sorted.c \
	su_atoi.c \
	parse_argv.c

SRC = $(SRC_COMMON) \
	enumerate_index_nodes.c \
	sort_few_numbers.c \
	k_sort.c \
	main.c

SRC_BONUS = $(SRC_COMMON) \
	bonus.c \
	execute_one_command.c \
	read_result_push_swap.c


OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))

all: create_directories $(NAME)

bonus: all $(NAME_BONUS)

create_directories:
	@mkdir -p $(OBJ_DIR)

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)

$(FT_PRINTF)/libftprintf.a:
	INCLUDE_DIR=$(PWD) $(MAKE) -C $(FT_PRINTF)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(FT_PRINTF) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(FT_PRINTF) fclean
	rm -f $(NAME)

re: fclean all

$(NAME): $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(NAME_BONUS): $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) $(LDFLAGS) -o $(NAME_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
