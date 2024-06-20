# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 16:10:29 by snunez-z          #+#    #+#              #
#    Updated: 2024/06/18 09:23:53 by snunez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################

NAME = minitalk

SERVER = server
CLIENT = client

SRC_SERVER = server.c 
SRC_CLIENT = client.c 

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

LIBFT = libft/libft.a

###################################################

all: $(SERVER) $(CLIENT)

$(SERVER) : $(LIBFT) $(OBJ_SERVER)
	cc $(OBJ_SERVER) -o $(SERVER) -Llibft/ -lft

$(CLIENT) : $(LIBFT) $(OBJ_CLIENT)
	cc $(OBJ_CLIENT) -o $(CLIENT) -Llibft/ -lft

%.o: %.c
	@echo "[ SRC ] Compilando $^"
	@cc -Wall -Werror -Wextra -c $<

$(LIBFT):
	@make -sC libft all
	
###################################################

clean:
	@make -sC libft clean
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	@make -sC libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
