NAME = libftprintf.a

SRC = ft_printf.c ft_utoa.c ft_htoa.c ft_htoa_lower.c ft_putchar_printf.c ft_putstr_printf.c ft_convertion_s.c ft_convertion_d_i.c ft_convertion_c.c ft_conv_porcentaje.c ft_convertion_u.c ft_convertion_hx.c ft_convertion_X.c ft_convertion_p.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	cc -I $(INCLUDE_DIR) -Wall -Werror -Wextra -c $<

$(NAME): $(OBJ) $(LIBFT_OBJ)
	ar -cr $(NAME) $(OBJ) $(LIBFT_OBJ)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
