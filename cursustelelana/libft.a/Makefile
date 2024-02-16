NAME = libft.a

SRC = ft_strlen.c ft_strdup.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_substr.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_itoa.c ft_putnbr_fd.c ft_split.c ft_strmapi.c ft_striteri.c ft_strjoin.c 

SRC_BONUS = ft_lstsize_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c 

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)
	
all: $(NAME)

%.o: %.c
	cc -Wall -Werror -Wextra -c $<

$(NAME): $(OBJ)
	ar -cr $(NAME) $(OBJ)

bonus: all $(OBJ_BONUS)
	ar -cr $(NAME) $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# Makefile consta de targets, dependencias y ordenes. Primero se ejecutan las dependencias, luego el target (con las ordenes que estan especificadas en el target).
# ejempo = make libft.a
# SE va al libft.a que es el $(NAME)y alli ve que depende de $(OBJ) asi que busca para cada .o su target que en este caso es la dependencia de .c y realizar la orden cc- W -W -W -c $>.
# Cuando ha realizado las dependencias, ejectura la orden ar -cr $(NAME) $(OBJ)
# clean borra los objetos
# flclean borra lso objetos y el resultado que es NAME que es en este caso libft.a
# el target libft.a depende de cada uno de los .o.Por cada .o se va a ir al target de la linea 6 (%.o: %.c) y va a ejecutar la orden de la linea 7 (cc......sustituyendo $< por el .c que corresponda).Con esos .o se crea el libft.a y eso se hace en el target all.POr eso all depende del target libft.a que es el que compila los .c.
#El comando ar ( crear archivos a partir de otros ), crea la libreria .a juntando todos los .o con las subordenes de crear y remplazar.













