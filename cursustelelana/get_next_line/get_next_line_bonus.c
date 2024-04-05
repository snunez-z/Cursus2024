/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:23:24 by snunez-z          #+#    #+#             */
/*   Updated: 2024/04/05 12:27:45 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "get_next_line_bonus.h"

#define MALLOC_SIZE 10

// porque como viste ayer, si no tenemos separados los buffer's de cada
// fd, acabamos mezclando (recuerda lo que pasó ayer en la última prueba
// que hiciste antes de irte a casa)
// Esta función recibe el fd del que queremos leer y va a retornar el t_gnl_bonus
// con el buffer, size e index específico de ese fd
// Pero vamos a ir haciéndola paso a paso
static t_gnl_bonus	*search_fd(int fd)
{
	// Define una estática de ese tipo
    static t_open_files	fd_to_open = {
		.fd_num = 0 // Lo inicializamos a cero porque todavía no hemos leído
					// de ningún fichero
	};

	size_t	index;
    t_gnl_bonus *one_file_data;

    // Busca en el array (campo "buffer" del struct "open_files") el elemento
    // que pertenezca al "fd" que te pasan como parámetro.
    // Si lo encuentras, devuelve el puntero a ese elemento del array
    // Si no lo encuentras, retorna NULL
	index = 0;
	while (index < fd_to_open.fd_num) // El array tiene 10240 elementos, pero no todos
											  // están ocupados, sólo los elementos que indique
											  // el campo "fd_num", así es que el bucle va has
											  // "fd_num" no hasta el 10240
	{
        one_file_data = &(fd_to_open.buffer[index]);
		if (one_file_data->fd == fd)
		// ENCONTRADO!!
			return (one_file_data);
		index++;
	}

	// Si salimos del bucle, es porque no lo hemos encontrado
    // Ocupamos un hueco libre. Cuál? El que indique fd_num, así es que, para no escribir
    // todo el rato "fd_to_open.fd_num" que es muy largo y no se entiende, hacemos esto:
    index = fd_to_open.fd_num;
    one_file_data = &(fd_to_open.buffer[index]);

    // Ahora inicializamos esa posición del array (a la que apunta "one_file_data")
    one_file_data->buffer_size = 0;
    one_file_data->buffer_index = 0;
    // Esta inicialización es importante, porque el campo "fd" es el que luego vamos
    // a usar para buscar
    one_file_data->fd = fd;

    // Hemos ocupado una posición más del array, así es que incrementamos fd_num
    fd_to_open.fd_num++;

    // Y, finalmente, retornamos el puntero a la posición que acabamos de inicializar
	return (one_file_data);
}

static int	read_one_char(int fd, char *dest)
{
    // Vamos a usar una variable solo, de tipo t_gnl_bonus
	t_gnl_bonus		*fd_data;

	fd_data = search_fd(fd);

	// Adaptamos el código que tenías hecho para que use fd_data en lugar de las
    // tres variables sueltas
	if (fd_data->buffer_index >= fd_data->buffer_size)
	{
		fd_data->buffer_size = read(fd, fd_data->buffer, BUFFER_SIZE);
		if (fd_data->buffer_size == -1)
			return (-1);
		if (fd_data->buffer_size == 0)
			return (0);
		fd_data->buffer_index = 0;
	}
	*dest = fd_data->buffer[fd_data->buffer_index];
	fd_data->buffer_index++;
	return (1);
}

char	*get_next_line(int fd)
{
	t_dstr	*line;
	char	ch;
	int		read_result;

	read_result = read_one_char(fd, &ch);
	if (read_result <= 0)
		return (NULL);
	line = dstr_create();
	if (line == NULL)
		return (NULL);
	while (read_result > 0)
	{
		line = dstr_append_char(line, ch);
		if (line == NULL)
			return (NULL);
		if (ch == '\n')
			return (dstr_reduce(line));
		read_result = read_one_char(fd, &ch);
	}
	if (read_result < 0)
		return (dstr_destroy(line));
	return (dstr_reduce(line));
}
/*#include <fcntl.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	fd;
	int	fd2;
	char	*line;
	char	*line2;

	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	fd2 = open(argv[2], O_RDONLY);
	line2 = get_next_line (fd2);
	while(line != NULL)
	{
		printf("%s:[%s]\n", argv [1], line);
		free (line);
		printf("%s:[%s]\n", argv[2], line2);
		line = get_next_line (fd);
		line2 = get_next_line (fd2);
	}
	close (fd);
	close (fd2);
	return (0);
}*/
