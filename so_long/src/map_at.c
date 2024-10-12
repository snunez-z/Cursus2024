#include "libft.h"
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

char	map_get_char_at(t_map *map, int column, int row)
{
	char	*line;
	
	line = list_node_at_position(map->rows, row);
	return (line[column]);
}

void	map_set_char_at(t_map *map, int column, int row, char ch)
{
	char	*line;
	
	line = list_node_at_position(map->rows, row);
	line[column] = ch;
}
