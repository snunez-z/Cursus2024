#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

size_t	ft_strlen(char	*block)
{
	size_t	i;

	if(!block)
		return(0);
	i = 0;
	while(block[i] != '\0')
		i++;
	return(i);
}

char	*ft_strndup(char	*block, size_t	size_line)
{
	char	*dup;
	size_t	i;

	if(!block)
		return(NULL);
	dup = malloc (size_line + 1);
	if(!dup)
			return(NULL);
	i = 0;
	while(i < size_line)
	{
		dup[i] = block [i];
		i++;	
	}
	dup[i] = '\0';
	return(dup);

}
char	*ft_strdup(char	*block)
{
		return(ft_strndup(block, ft_strlen(block)));
}
char	*ft_strchr(char	*block, char ch)
{
	char	*pos;

	if(!block)
		return(NULL);
	pos = block;
	while(*pos != '\0')
	{
		if(*pos == ch)
			return(pos + 1);
		pos++;
	}
	return(NULL);
}
char	*skip_to_next_line(char	*block)
{
	char	*next_line;
	char	*end_of_line;

	if(!block)
		return(NULL);
	end_of_line = ft_strchr (block, '\n');
	if(end_of_line == NULL)
	{
		free(block);
		return(NULL);
	}
	next_line = ft_strdup(end_of_line);
	free(block);
	return(next_line);
}

char	*ft_line(char	*block)
{
	char	*end_of_line;
	char	*line;
	size_t	size_line;

	if(block == NULL || block [0] == '\0')
		return(NULL);
	end_of_line = ft_strchr  (block, '\n');
	if(end_of_line == NULL)
		line = ft_strdup(block);
	else 
	{
		size_line = end_of_line - block;
		line = ft_strndup(block, size_line);
	}
	return(line);
}
char	*ft_strjoin(char	*block, char	*buffer)
{
	char	*join;
	size_t	pos;
	size_t	pos2;

	if(ft_strlen(buffer) == 0)
		return (block);
	join = malloc ((ft_strlen (block) + ft_strlen(buffer) + 1));
	if( !join)
	{
		free(block);
		return (NULL);
	}
	pos = 0;
	while(block[pos] == '\0')
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
		buffer[bytes_read] = '\0';
		block = ft_strjoin(block, buffer);
	}
	return(block);
}

char	*get_next_line(int fd)
{
	static char	*block;
	char		*line;

	if(fd < 0)
		return(NULL);
	if (block == NULL)
	{
		block = malloc(1);
		if(block != NULL)
			block[0] = '\0';
	}
	block = ft_read(fd, block);
	if(!block)
		return(NULL);
	line = ft_line(block);
	block = skip_to_next_line(block);
	return(line);
}
int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("readme.md", O_RDONLY);
	if(fd < 0)
		return (0);
	buffer = get_next_line(fd);
	while(buffer!= NULL)
	{
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (0);
}
