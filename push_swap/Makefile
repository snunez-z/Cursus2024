
NAME = push_swap

SRC_DIR = ./src
OBJ_DIR = ./obj

LIBFT = ./libft
FT_PRINTF = $(LIBFT)/ft_printf

CC = cc
CFLAGS = -Werror -Wall -Wextra -I $(INC_DIR) -I $(LIBFT) -I $(FT_PRINTF) -I 
LDFLAGS = -L $(LIBFT) -L $(FT_PRINTF) -L -lftprintf 

SRC = list_number.c list_stack_push.c move_count.c movement_min_number.c rotate_resverse.c rotate.c sort_stacks.c su_atoi.c swap.c main.c move_count.h push_swap.h 

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIBFT)/libft.a:
	INCLUDE_DIR=$(PWD) make -C $(LIBFT) all

$(FT_PRINTF)/libftprintf.a:
	INCLUDE_DIR=$(PWD) make -C $(FT_PRINTF) all

clean:
	make -C $(LIBFT) clean
	make -C $(FT_PRINTF) clean
	-rm $(OBJ_DIR)/*.o $(NAME)

fclean: clean
	make -C $(LIBFT) fclean
	make -C $(FT_PRINTF) fclean

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re
