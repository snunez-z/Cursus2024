#! /bin/bash

# gcc -I ../../MLX42/include/ -Wall -Werror -Wextra *.c -L ../../MLX42/build/ -lmlx42 -lX11 -lglfw
gcc -I ./minilibx -Wall -Werror -Wextra *.c -L ./minilibx -lmlx -lX11 -lXext
