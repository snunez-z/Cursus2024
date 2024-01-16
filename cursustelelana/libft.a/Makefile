NAME = libft.a
OBJ = ft_strlen.o ft_strdup.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o ft_tolower.o ft_toupper.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o ft_calloc.o

all: $(OBJ)

%.o: %.c
	cc -Wall -Werror -Wextra -c $<

$(NAME): all
	ar -cr $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

# Makefile consta de targets, dependencias y ordenes. Primero se ejecutan las dependencias, luego el target (con las ordenes que estan especificadas en el target).
# ejempo = make libft.a
# SE va al libft.a que es el $(NAME)y alli ve que depende de $(OBJ) asi que busca para cada .o su target que en este caso es la dependencia de .c y realizar la orden cc- W -W -W -c $>.
# Cuando ha realizado las dependencias, ejectura la orden ar -cr $(NAME) $(OBJ)
# clean borra los objetos
# flclean borra lso objetos y el resultado que es NAME que es en este caso libft.a

















