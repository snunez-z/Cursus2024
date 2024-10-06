#include "dstr.h"
#include "list.h"
#include "map.h"

char	map_at(t_map *map, int column, int row, char ch)
{
	return (dstr_char_at(list_get(map->rows, row), column, ch));
}
