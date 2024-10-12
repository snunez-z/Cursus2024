#include "libft.h"
#include "dstr.h"
#include "map.h"

static char	*list_node_at_position(t_list *list, int pos)
{
	int index;
	t_list	*node;

	index = 0;
	node = list;
	while (index < pos)
	{
		node = node->next;
		index++;
	}
	return ((char*)node->content);
}

char	map_at(t_map *map, int column, int row, char ch)
{
	char	*line;
	char	previous;
	
	line = list_node_at_position(map->rows, row);
	previous = line[column];
	if (ch != 0)
		line[column] = ch;
	return (previous);
}
