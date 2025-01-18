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
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	char *pos;

	if (!str)
		return (NULL);
	pos = str;
	while (*pos != '\0')
	{
		if (*pos == c)
			return (pos + 1);
		pos++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	pos;
	size_t	pos_2;
	char	*join;

	if (ft_strlen(str2) == 0)
		return (str1);
	join = malloc((ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!join)
	{
		free(str1);
		return (NULL);
	}
	pos = 0;
	while (str1[pos] != '\0')
	{
		join[pos] = str1[pos];
		pos++;
	}

	pos_2 = 0;
	while (str2[pos_2] != '\0')
	{
		join[pos] = str2[pos_2];
		pos++;
		pos_2++;
	}
	join[pos] = '\0';
	free(str1);
	return (join);
}

char	*ft_strndup(char *str, size_t len)
{
	size_t	i;
	char	*dup;

	if (!str)
		return (NULL);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup(char *s1)
{
	return ft_strndup(s1, ft_strlen(s1));
}

char	*ft_skip_to_next_line(char *block)
{
	char	*end_of_line;
	char	*next_line;

	if (!block)
		return (NULL);
	end_of_line = ft_strchr(block, '\n');
	if (end_of_line == NULL)
	{
		free(block);
		return (NULL);
	}
	next_line = ft_strdup(end_of_line); // copia desde el \n hasta el \0.
	free(block);
	return (next_line);
}

char	*ft_line(char *block)
{
	char	*end_of_line;
	char	*ln;
	size_t	line_size;

	if (block == NULL || block[0] == '\0')
		return (NULL);
	end_of_line = ft_strchr(block, '\n');
	if (end_of_line == NULL) // si no lo ha encontrado el \n
		ln = ft_strdup(block); // la linea es todo el bloque
	else
	{
		line_size = end_of_line - block;
		ln = ft_strndup(block, line_size);
	}
	return (ln);
}

char	*ft_read(int fd, char *block)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	while (block != NULL && !ft_strchr(block, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0) //si he llegado al final
			return (block);
		if (bytes_read == -1) // si ha fallado la lectura 
		{
			free(block);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		block = ft_strjoin(block, buffer);
	}
	return (block);
}

char	*get_next_line(int fd)
{
	static char	*block;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (block == NULL) // si es la primera veZ/para inicializar la estatica
	{
		block = malloc(1); // un byte porque inicialmente esta a cero, 1 byte para el barra cero
		if (block != NULL)
			block[0] = '\0';
	}
	block = ft_read(fd, block);//lee bloques 
	if (!block)
		return (NULL);
	line = ft_line(block); // extrae una linea
	block = ft_skip_to_next_line(block); // skip hace que se salte lo copiado y pase a lo siguiente
	return (line);
}

/*int	main (void)
{
	int fd;
	char	*buffer;
	
	fd = open("readme.md", O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer != NULL)
	{
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line (fd);
		
	}
	return (0);
}*/
