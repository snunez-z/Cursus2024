NAME = libftprintf.a

SRC = ft_printf.c ft_utoa.c ft_htoa.c ft_htoa_lower.c  

OBJ = $(SRC:.c=.o)

all: libft_all $(NAME)

%.o: %.c
	cc -Wall -Werror -Wextra -c $<

$(NAME): libft_name $(OBJ)
	ar -cr $(NAME) $(OBJ)

clean: libft_clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: libft_fclean clean
	rm -f $(NAME)

re: libft_re fclean all

.PHONY: all clean fclean re bonus

# Targets para el libft
LIBFT_PATH = ./libft

libft_all:
	make -C $(LIBFT_PATH) all

libft_name:
	make -C $(LIBFT_PATH) libft.a

libft_clean:
	make -C $(LIBFT_PATH) clean

libft_fclean:
	make -C $(LIBFT_PATH) fclean

libft_re:
	make -C $(LIBFT_PATH) re
