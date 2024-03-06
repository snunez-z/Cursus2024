NAME = libftprintf.a

SRC = ft_printf.c ft_utoa.c ft_htoa.c ft_htoa_lower.c ft_putchar_printf.c ft_putstr_printf.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft

LIBFT_OBJ = $(LIBFT_PATH)/ft_*.o

all: libft_all $(NAME)

%.o: %.c
	cc -Wall -Werror -Wextra -c $<

$(NAME): $(OBJ) $(LIBFT_OBJ)
	ar -cr $(NAME) $(OBJ) $(LIBFT_OBJ)

clean: libft_clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: libft_fclean clean
	rm -f $(NAME)

re: libft_re fclean all

.PHONY: all clean fclean re bonus

# Targets para el libft
libft_all:
	make -C $(LIBFT_PATH) all

libft_clean:
	make -C $(LIBFT_PATH) clean

libft_fclean:
	make -C $(LIBFT_PATH) fclean

libft_re:
	make -C $(LIBFT_PATH) re
