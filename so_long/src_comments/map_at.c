#include "dstr.h"
#include "list.h"
#include "map.h"

char	map_at(t_map *map, int column, int row, char ch)
{
	t_dstr	*line;
	
	line = list_get(map->rows, row);
	return (dstr_char_at(line, column, ch));
}
