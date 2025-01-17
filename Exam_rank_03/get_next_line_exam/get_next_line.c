/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:45:58 by snunez-z          #+#    #+#             */
/*   Updated: 2025/01/17 13:41:46 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
/*Propósito: Busca la primera aparición de un carácter (c) en la cadena (s).
Funcionamiento:
Si la cadena es NULL, retorna NULL.
Recorre la cadena buscando el carácter c. Si lo encuentra, retorna un puntero al siguiente carácter.
Si c es el carácter nulo ('\0'), retorna un puntero al final de la cadena.
Si no encuentra c, retorna NULL.
Uso: Detecta si una línea contiene un salto de línea (\n) y encuentra su posición.
 */
char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i] + 1);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}/* Propósito: Concatena dos cadenas (board y buffer) en una nueva.
Funcionamiento:
Si buffer está vacío, retorna board directamente.
Reserva memoria suficiente para ambas cadenas juntas.
Copia el contenido de board y luego de buffer en el nuevo bloque de memoria.
Libera la memoria de board y retorna la nueva cadena.
Uso: Une el contenido previamente leído (board) con nuevos datos del buffer.*/

char	*ft_strjoin(char *board, char *buffer)
{
	size_t	i;
	size_t	z;
	char	*board_dir;

	if (ft_strlen(buffer) == 0)
		return (board);
	board_dir = malloc((ft_strlen(board) + ft_strlen(buffer) + 1));
	if (!board_dir)
	{
		free(board);
		return (NULL);
	}
	i = -1;
	while (board[++i] != '\0')
		board_dir[i] = board[i];
	z = 0;
	while (buffer[z] != '\0')
		board_dir[i++] = buffer[z++];
	board_dir[i] = '\0';
	free(board);
	return (board_dir);
}
/* Propósito: Crea una copia de la cadena s1.
Funcionamiento:
Si s1 es NULL, retorna NULL.
Calcula la longitud de la cadena, reserva memoria y copia su contenido en la nueva ubicación.
Uso: Se utiliza para duplicar líneas u otras cadenas en funciones como ft_new_line y ft_line.*/
char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*s2;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*Propósito: Actualiza board eliminando el contenido anterior a la primera línea.
Funcionamiento:
Si board es NULL o no contiene \n, libera board y retorna NULL.
Encuentra la posición del primer \n, duplica el resto de la cadena y libera board.
Retorna la nueva cadena que empieza después del \n.
Uso: Mantiene en board solo los datos no procesados tras devolver una línea.*/
char	*ft_new_line(char *board)
{
	char	*new_line;

	if (!board)
		return (NULL);
	if (!ft_strchr(board, '\n'))
	{
		free(board);
		return (NULL);
	}
	new_line = ft_strchr(board, '\n');
	new_line = ft_strdup(new_line);
	free(board);
	return (new_line);
}
/*Propósito: Extrae la primera línea de board.
Funcionamiento:
Si board está vacío, retorna NULL.
Si no contiene \n, duplica toda la cadena.
Si contiene \n, reserva memoria hasta su posición y copia el contenido, incluyendo \n.
Uso: Devuelve una línea lista para ser utilizada.*/
char	*ft_line(char *board)
{
	char	*ln;
	int		i;

	i = 0;
	if (!board[i])
		return (NULL);
	if (!ft_strchr(board, '\n'))
		ln = ft_strdup(board);
	else
	{
		ln = malloc(ft_strchr(board, '\n') - board + 1);
		if (!ln)
			return (NULL);
		while (board[i] != '\n')
		{
			ln[i] = board[i];
			i++;
		}
		ln[i] = board[i];
		ln[i + 1] = '\0';
	}
	return (ln);
}
/*Propósito: Lee datos del descriptor de archivo y los almacena en board.
Funcionamiento:
Reserva un buffer temporal.
Mientras no haya un \n en board y se sigan leyendo datos (read > 0):
Lee hasta BUFFER_SIZE bytes del archivo.
Une el contenido leído con board usando ft_strjoin.
Libera el buffer y retorna board.
Uso: Llena board con datos hasta encontrar un \n o el final del archivo.*/
char	*ft_read(int fd, char *board)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(board);
		return (NULL);
	}
	bytes_read = 1;
	while (board && !ft_strchr(board, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(board);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		board = ft_strjoin(board, buffer);
	}
	free(buffer);
	return (board);
}
/*Propósito: Gestiona la lógica para leer una línea completa desde un archivo.
Funcionamiento:
Verifica si el descriptor fd y BUFFER_SIZE son válidos.
Si es la primera llamada, inicializa board.
Llama a ft_read para leer datos adicionales.
Extrae la línea completa con ft_line.
Actualiza board con los datos restantes tras la línea extraída usando ft_new_line.
Retorna la línea.
Uso: Es la función principal que los usuarios llaman para obtener líneas consecutivas desde un archivo. */
char	*get_next_line(int fd)
{
	static char	*board;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!board)
	{
		board = malloc(1);
		if (!board)
			return (NULL);
		board[0] = '\0';
	}
	board = ft_read(fd, board);
	if (!board)
		return (NULL);
	line = ft_line(board);
	board = ft_new_line(board);
	return (line);
}
/*El programa mantiene un board estático que almacena los datos leídos pero no procesados.
Al llamar a get_next_line, se lee más contenido del archivo (si es necesario), se extrae una línea y se actualiza board.
Este proceso se repite hasta que no haya más líneas que leer. */
