
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(char	*str)
{
	size_t	i;

	if(!str)
		return(0);
	i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}

char	*ft_strchr(char	*str, char ch)
{
	char	*pos;

	if(!str)
		return(NULL);
	pos = str;
	while(*pos != '\0')
	{
		if(*pos == ch)
			return(pos + 1);
		pos++;
	}
	return(NULL);
}

char	*ft_strndup(char	*block, size_t	len)
{
	char	*dup;
	size_t	i;

	if(!block)
		return(NULL);
	dup = malloc (len + 1);
	if(!dup)
		return(NULL);
	i = 0;
	while(i < len)
	{
		dup[i] = block[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}
char	*ft_strdup(char	*block)
{
	return(ft_strndup(block, ft_strlen(block)));
}
char	*ft_strjoin(char	*block, char *buffer)
{
	size_t	pos;
	size_t	pos2;
	char	*join;

	if(ft_strlen(buffer) == 0)
		return(block);
	join = malloc (ft_strlen(block) + ft_strlen (buffer) + 1);
	if(!join)
	{
		free(block);
		return(NULL);
	}
	pos = 0;
	while(block[pos] != '\0')
	{
		join[pos] = block[pos];
		pos++;
	}
	pos2 = 0;
	while(buffer[pos2] != '\0')
	{
		join[pos] = buffer[pos2];
		pos++;
		pos2++;
	}
	join[pos] = '\0';
	free(block);
	return(join);
}
char	*skip_to_next_line(char	*block)
{
	char	*next_line;
	char	*end_of_line;

	if(!block)
		return(NULL);
	end_of_line = ft_strchr(block, '\n');
	if (end_of_line == NULL)
	{
		free(block);
		return(NULL);
	}
	next_line = ft_strdup(end_of_line);
	free (block);
	return(next_line);
}	

char	*ft_line(char	*block)
{
	char	*line;
	char	*end_of_line;
	size_t	line_size;

	if(block == NULL || block[0] == '\0')
		return(NULL);
	end_of_line = ft_strchr(block, '\n');
	if(end_of_line == NULL)
		line = ft_strdup(block);
	else
	{
		line_size = end_of_line - block;
		line = ft_strndup(block, line_size);
	}
	return(line);
}

char	*ft_read(int fd, char	*block)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	while(block != NULL && !ft_strchr(block, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read == 0)
			return(block);
		if(bytes_read == -1)
		{
			free(block);
			return(NULL);
		}
		buffer [bytes_read] = '\0';
		block = ft_strjoin(block, buffer);
	}
	return(block);
}

char	*get_next_line(int fd)
{
	static char *block;
	char		*line;

	if(fd < 0)
		return(NULL);
	if(block == NULL)
	{
		block = malloc(1);
		if(block != NULL)
			block[0] = '\0';
	}
	block = ft_read(fd, block);
	if(!block)
		return(NULL);
	line= ft_line(block);
	block = skip_to_next_line(block);
	return(line);
}

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("readme.md", O_RDONLY);
	buffer = get_next_line(fd);
	while(buffer != NULL)
	{
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	return(0);
}

