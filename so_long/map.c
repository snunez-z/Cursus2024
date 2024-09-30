#include <fcntl.h>
#include <stdlib.h>
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
	list_t	*rows;
	dstr_t	*line;

	rows = NULL;
	line = read_line(fd);
	while(line != NULL && dstr_length(line) > 0)
	{
		rows = list_append(rows, line, destroy_line);
		if (!rows)
			return (NULL);
		line = read_line(fd);
	}
	if (line == NULL)
	{
		list_destroy(rows, destroy_line);
		return (NULL);
	}
	dstr_destroy(line);
	return (rows);
}

static int	find_player(map_t	*map)
{
	size_t	x;
	size_t	y;
	size_t	width;
	size_t	height;
	char	ch;

	width = map_get_width(map);
	height = map_get_height(map);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ch = map_at(map, x, y);
			if (ch == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				map->at_player = '0';
				return (1);
			}
			x++;
		}
		y++;
	}

	return (0);
}

static char set_char_at(map_t *map, size_t x, size_t y, char ch)
{
	dstr_t *row = list_get(map->rows, y);
	return dstr_set_char_at(row, x, ch);
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

	map = (map_t*)util_calloc(sizeof(map_t));
	if (map != NULL)
	{
		util_write("Reading map file: ");
		util_write_line(file_name);
		map->rows = read_file(fd);
	}
	close(fd);

	if (!map->rows)
	{
		map_destroy(map);
		return (NULL);
	}
	find_player(map);
	return (map);
}

void	map_destroy(map_t *map)
{
	if (!map)
		return;
	if (map->rows != NULL)
		list_destroy(map->rows, destroy_line);
	free(map);
}

size_t	map_get_width(map_t *map)
{
	return dstr_length((dstr_t*)list_get(map->rows, 0));
}

size_t	map_get_height(map_t *map)
{
	return list_size(map->rows);
}

char	map_at(map_t *map, size_t column, size_t row)
{
	return dstr_char_at((dstr_t*)list_get(map->rows, row), column);
}

void	map_write(map_t *map, int fd)
{
	list_t	*node;

	node = map->rows;
	while(node != NULL)
	{
		dstr_write((dstr_t*)node->data, fd, 1);
		node = node->next;
	}
}

void	map_move_player(map_t *map, int inc_x, int inc_y)
{
	size_t	new_x;
	size_t	new_y;

	new_x = map->player_x + inc_x;
	new_y = map->player_y + inc_y;
	if (map_at(map, new_x, new_y) != '1')
	{
		set_char_at(map, map->player_x, map->player_y, map->at_player);
		map->player_x = new_x;
		map->player_y = new_y;
		map->at_player = set_char_at(map, map->player_x, map->player_y, 'P');
		if (map->at_player == 'C')
			map->at_player = '0';
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