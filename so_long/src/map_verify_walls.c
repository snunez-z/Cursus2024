#include <stddef.h>
#include "libft.h"
#include "ft_printf.h"
#include "dstr.h"
#include "map.h"
#include "map_verifications.h"

static int	verify_all_walls(t_list *node)
{
	char	*buffer;

	buffer = (char*)node->content;
	while (*buffer)
	{
		if (*buffer != MAP_WALL_CHAR) 
			return (0);
		buffer++;
	}
	return (1); 
}

static int	verify_side_walls(t_list *node)
{
	char	*line;
	int		width;

	line = (char*)node->content;
	width = ft_strlen(line);
	if (line[0] != MAP_WALL_CHAR || line[width - 1] != MAP_WALL_CHAR)
		return (0);
	return (1);
}

int	map_verify_walls(t_map *map)
{
	t_list	*node;

	ft_printf("Verifying map walls...\n");
	node = map->rows;
	if (!verify_all_walls(node)) 
		return (0);
	node = node->next;
	while(node->next != NULL)
	{
		if (!verify_side_walls(node))
			return (0);
		node = node->next;
	}
	if (!verify_all_walls(node)) 
		return (0);
	return (1);
}
