#include <fcntl.h>
#include <unistd.h>
#include "dstr.h"
#include "list.h"
#include "map.h"
#include "util.h"

static void	destroy_line(void *line)
{
	dstr_destroy((dstr_t*) line);
}

static int	read_line_into_buffer(int fd, dstr_t *line)
{
	ssize_t	read_result;
	char ch;

	read_result = read(fd, &ch, 1);
	while(read_result == 1 && ch != '\n')
	{
		if (!dstr_append_char(line, ch))
		{
			util_write_line("Not enough memory");
			return (0);
		}
		read_result = read(fd, &ch, 1);
	}
	if (read_result < 0)
	{
		util_write_line("Error reading map file");
		dstr_destroy(line);
		return (0);
	}
	return (1);
}

static dstr_t	*read_line(int fd)
{
	dstr_t	*line;

	line = dstr_create();
	if (!line)
	{
		util_write_line("Not enough memory");
		return (NULL);
	}
	if(!read_line_into_buffer(fd, line))
		return (NULL);
	return (line);
}

static list_t	*read_file(int fd)
{
	list_t	*map;
	dstr_t	*line;

	map = NULL;
	line = read_line(fd);
	while(line != NULL && dstr_length(line) > 0)
	{
		map = list_append(map, line, destroy_line);
		if (!map)
			return (NULL);
		line = read_line(fd);
	}
	if (line == NULL)
	{
		map_destroy(map);
		return (NULL);
	}
	dstr_destroy(line);
	return (map);
}

map_t	*map_read(const char *file_name)
{
	map_t	*map;
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		util_write("Unable to open map file: ");
		util_write_line(file_name);
		return (NULL);
	}

	util_write("Reading map file: ");
	util_write_line(file_name);
	map = read_file(fd);
	close(fd);
	return (map);
}

void	map_destroy(map_t *map)
{
	list_destroy(map, destroy_line);
}

size_t	map_get_width(map_t *map)
{
	return dstr_length((dstr_t*)list_get(map, 0));
}

size_t	map_get_height(map_t *map)
{
	return list_size(map);
}

char	map_at(map_t *map, size_t row, size_t column)
{
	return dstr_char_at((dstr_t*)list_get(map, row), column);
}

void	map_write(map_t *map, int fd)
{
	list_t	*node;

	node = map;
	while(node != NULL)
	{
		dstr_write((dstr_t*)node->data, fd, 1);
		node = node->next;
	}
}

/*
int main(int argc, char **argv)
{
	list_t	*map;

	if (argc < 2)
		return 0;
	map = map_read(argv[1]);
	map_write(map, 0);
	map_destroy(map);
	return 0;
}
*/