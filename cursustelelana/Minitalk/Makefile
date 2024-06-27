# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 16:10:29 by snunez-z          #+#    #+#              #
#    Updated: 2024/06/26 17:44:36 by snunez-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################

NAME = minitalk

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_SERVER = server.c 
SRC_CLIENT = client.c 

SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c 

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

LIBFT = libft/libft.a

###################################################

all: $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

$(SERVER) : $(LIBFT) $(OBJ_SERVER)
	cc $(OBJ_SERVER) -o $(SERVER) -Llibft/ -lft

$(CLIENT) : $(LIBFT) $(OBJ_CLIENT)
	cc $(OBJ_CLIENT) -o $(CLIENT) -Llibft/ -lft

$(SERVER_BONUS) : $(LIBFT) $(OBJ_SERVER_BONUS)
	cc $(OBJ_SERVER_BONUS) -o $(SERVER_BONUS) -Llibft/ -lft

$(CLIENT_BONUS) : $(LIBFT) $(OBJ_CLIENT_BONUS)
	cc $(OBJ_CLIENT_BONUS) -o $(CLIENT_BONUS) -Llibft/ -lft

%.o: %.c
	@echo "[ SRC ] Compilando $^"
	@cc -Wall -Werror -Wextra -c $<

$(LIBFT):
	@make -sC libft all
	
###################################################

clean:
	make -sC libft clean
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)$ (OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	@make -sC libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
