/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:36:02 by snunez-z          #+#    #+#             */
/*   Updated: 2024/03/20 11:45:42 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "get_next_line.h"

#define MALLOC_SIZE 10

static	int	read_one_char(int fd, char *dest)
{
	static char buffer[BUFFER_SIZE];
	static int	buffer_size = 0;
	static int	buffer_index = 0;

	if (buffer_index >= buffer_size) // como estan inicializados a cero, entran pro primera vez si o si.
	{
		buffer_size = read(fd, buffer, BUFFER_SIZE);
		if (buffer_size == -1)
			return (-1);
		if (buffer_size == 0)
			return (0); // Igual o menor que cero, significa que ha habido un error y no se va a poder leer.
		buffer_index = 0;// se posiciona en el primer caracater del siguiente trozo que ha leido.
	}

	*dest = buffer[buffer_index];// se guarda el carcater en dest
	buffer_index++;
	return 1;// indica que retorna un caracter
}

char	*get_next_line(int fd)
{
	dstr_t	*line;
	char	ch;
	int		read_result;

	read_result = read_one_char(fd, &ch);// leer un char
	if (read_result <= 0)// Si intento leer un carcater, el primero, y no hay nada....
		return (NULL);

	line = dstr_create(); // reserva memoria del struct y del buffer
	while (line != NULL && read_result > 0) // Si al intentar agrandar la memoria del buffer falla, retorna null tal como indica la funcion append_char. y si no hay nada que leer.
	{
		line = dstr_append_char(line, ch); // Lo agranda si es necesario
		if (line == NULL)
			return (NULL);
		if (ch == '\n')
			return (dstr_reduce(line));// si es el final de linea me salgo y en caso necesario se reduce el buffer al tamaño que hemos leido.
		read_result = read_one_char(fd, &ch);// leer el siguiente caracter.
	} //si llega aqui es que no ha podido leer o ha fallado la reserva de memoria del nuevo buffer o que no haya nada mas que leer.

	if (line == NULL)// que haya fallado la memoria)
		return NULL;

	if (read_result < 0) // haya fallado al leer
		return (dstr_destroy(line)); // tengo que liberar la memoria de todo

	return (dstr_reduce(line)); // No hay mas, y lo necesito reducir y retornar. 
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line (fd);
	while(line != NULL)
	{
		printf("%s", line);
		free (line);
		line = get_next_line (fd);
	}
	close (fd);
	return (0);
} */
