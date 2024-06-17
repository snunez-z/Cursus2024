# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 16:10:29 by snunez-z          #+#    #+#              #
#    Updated: 2024/06/17 16:10:34 by snunez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRC = server.c client.c 

OBJ = $(SRC:.c=.o)

PRINTF_PATH = ./libftprintf

PRINTF_OBJ = $(PRINTF_PATH:.c=.o)

#PRINTF_OBJ = $(PRINTF_PATH)/libft/ft_atoi.o $(PRINTF_PATH)/libft/ft_memset.o $(PRINTF_PATH)/libft/ft_strlen.o 

all: libft_all $(NAME)

%.o: %.c
	cc -Wall -Werror -Wextra -c $<

$(NAME): $(OBJ) $(PRINTF_OBJ)
	ar -cr $(NAME) $(OBJ) $(PRINTF_OBJ)

clean: libft_clean
	rm -f $(OBJ) 

fclean: libft_fclean clean
	rm -f $(NAME)

re: libft_re fclean all

.PHONY: all clean fclean re bonus

# Targets para el ft_printf/libft
libft_all:
	make -C $(PRINTF_PATH) all

libft_clean:
	make -C $(PRINTF_PATH) clean

libft_fclean:
	make -C $(PRINTF_PATH) fclean

libft_re:
	make -C $(PRINTF_PATH) re


