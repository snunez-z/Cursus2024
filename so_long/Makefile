NAME = so_long

PWD = $(shell pwd)

LIB = ./lib
LIBFT = ./libft
FT_PRINTF = ./ft_printf
MINILIBX = ./minilibx

CC = cc
CFLAGS = -Werror -Wall -Wextra -I $(LIBFT) -I $(FT_PRINTF) -I $(MINILIBX)
LDFLAGS = -L $(LIB) -lftprintf -lft -lX11 -lXext -lmlx

SRC = dstr.c game.c images.c list.c main.c map.c util.c
OBJ = $(SRC:.c=.o)

all: libs $(NAME)

libs:
	INCLUDE_DIR=$(PWD) make -C $(LIBFT) all
	cp $(LIBFT)/libft.a $(LIB)
	INCLUDE_DIR=$(PWD) make -C $(FT_PRINTF) all
	cp $(FT_PRINTF)/libftprintf.a $(LIB)
	INCLUDE_DIR=$(PWD) make -C $(MINILIBX) all
	cp $(MINILIBX)/libmlx.a $(LIB)

clean:
	make -C $(LIBFT) clean
	make -C $(FT_PRINTF) clean
	make -C $(MINILIBX) clean
	rm $(LIB)/* *.o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) -I $(INCLUDE_DIR) $(CFLAGS) -c $<

