#include <stddef.h>
#include "ft_printf.h"
#include "dstr.h"
#include "list.h"
#include "map.h"
#include "map_verifications.h"

static int	verify_all_walls(t_dstr *row)
{
	int	len;
	int	index;
	char	ch;

	len = dstr_length(row);
	index = 0;
	while (index < len)
	{
		ch = dstr_char_at(row, index, 0);
		if (ch != MAP_WALL_CHAR) 
			return (0);
		index++;
	}
	return (1); 
}

static int	verify_side_walls(t_dstr *row)
{
	int	width;

	width = dstr_length(row);
	if (dstr_char_at(row, 0, 0) != MAP_WALL_CHAR 
		|| dstr_char_at(row, width - 1, 0) != MAP_WALL_CHAR) 
		return (0);
	return (1);
}

int	map_verify_walls(t_map *map)
{
	t_dstr	*line;
	int	index;

	ft_printf("Verifying map walls...\n");
	line = list_get(map->rows, 0);
	if (verify_all_walls(line) == 0) 
		return (0);
	line = list_get(map->rows, map->height - 1);
	if (verify_all_walls(line) == 0) 
		return (0);
	index = 1;
	while (index < (map->height - 1))
	{
		if (!verify_side_walls(list_get(map->rows, index)))
			return (0);
		index++;
	}
	return (1);
}
