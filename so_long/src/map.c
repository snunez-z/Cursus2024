#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "dstr.h"
#include "list.h"
#include "map.h"
#include "util.h"

struct count_data_s
{
	char	char_to_find;
	int	count;
};

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
			return (0);
		read_result = read(fd, &ch, 1);
	}
	if (read_result < 0)
	{
		ft_printf("Error\nError reading map file\n");
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
		return (NULL);
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

static int	find_player(map_t *map, int x, int y, char ch, void *data)
{
	(void)data;
	if (ch == 'P')
	{
		map->player_x = x;
		map->player_y = y;
		map->at_player = '0';
		return (0);
	}

	return (1);
}

static char set_char_at(map_t *map, int x, int y, char ch)
{
	dstr_t *row = list_get(map->rows, y);
	return dstr_set_char_at(row, x, ch);
}

static int	count_char_function(map_t *map, int x, int y, char ch, void *data)
{
	struct count_data_s	*count_data;

	(void)map;
	(void)x;
	(void)y;
	count_data = (struct count_data_s*)data;
	if (ch == count_data->char_to_find)
		count_data->count++;
	return (1);
}

map_t	*map_read(const char *file_name)
{
	map_t	*map;
	int	fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		ft_printf("Error\nUnable to open map file: %s\n", file_name);
		return (NULL);
	}

	map = (map_t*)util_calloc(sizeof(map_t));
	if (map != NULL)
		map->rows = read_file(fd);
	close(fd);

	if (!map || !map->rows)
	{
		map_destroy(map);
		return (NULL);
	}
	map_loop(map, find_player, NULL);
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

int	map_get_width(map_t *map)
{
	return (int)dstr_length((dstr_t*)list_get(map->rows, 0));
}

int	map_get_height(map_t *map)
{
	return (int)list_size(map->rows);
}

char	map_at(map_t *map, int column, int row)
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

int	map_move_player(map_t *map, int inc_x, int inc_y)
{
	int	new_x;
	int	new_y;

	new_x = map->player_x + inc_x;
	new_y = map->player_y + inc_y;
	if (new_x < 0 || new_y < 0
		|| new_x >= map_get_width(map) || new_y >= map_get_height(map)
		|| map_at(map, new_x, new_y) == '1')
		return (0);

	set_char_at(map, map->player_x, map->player_y, map->at_player);
	map->player_x = new_x;
	map->player_y = new_y;
	map->at_player = set_char_at(map, map->player_x, map->player_y, 'P');
	if (map->at_player == 'C')
		map->at_player = '0';

	return (1);
}

int	map_count_chars(map_t *map, char ch)
{
	struct count_data_s	count_data;

	count_data.char_to_find = ch;
	count_data.count = 0;

	map_loop(map, count_char_function, &count_data);
	return count_data.count;
}

void	map_loop(map_t *map, int (*fn)(map_t*, int, int, char, void*), void *data)
{
	int	x;
	int	y;
	int	width;
	int	height;
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
			if (!fn(map, x, y, ch, data))
				return;
			x++;
		}
		y++;
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