NAME = libftprintf.a

SRC = ft_printf.c ft_utoa.c ft_htoa.c ft_htoa_lower.c ft_putchar_printf.c ft_putstr_printf.c ft_convertion_s.c ft_convertion_d_i.c ft_convertion_c.c ft_conv_porcentaje.c ft_convertion_u.c ft_convertion_hx.c ft_convertion_X.c ft_convertion_p.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft

LIBFT_OBJ = $(LIBFT_PATH: .c = .o) 
#$(LIBFT_PATH)/ft_strlen.o $(LIBFT_PATH)/ft_calloc.o $(LIBFT_PATH)/ft_itoa.o $(LIBFT_PATH)/ft_strlcpy.o $(LIBFT_PATH)/ft_bzero.o $(LIBFT_PATH)/ft_memset.o $(LIBFT_PATH)/ft_putchar_fd.o $(LIBFT_PATH)/ft_putstr_fd.o $(LIBFT_PATH)/ft_tolower.o

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
