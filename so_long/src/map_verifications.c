#include <stddef.h>
#include "libft.h"
#include "ft_printf.h"
#include "dstr.h"
#include "map.h"
#include "map_verifications.h"

static	int	count_function(t_map_loop *map_loop) 
{
	t_count_data	*count_data;

	count_data = (t_count_data *)map_loop->data;
	if (map_loop->ch == MAP_PLAYER_CHAR) 
	{
		map_loop->map->player_x = map_loop->x; 
		map_loop->map->player_y = map_loop->y;
		map_loop->map->at_player = '0'; 
		count_data->player_count++;
	}
	else if (map_loop->ch == MAP_EXIT_CHAR)
		count_data->exit_count++;
	else if (map_loop->ch == MAP_FOOD_CHAR)
		map_loop->map->food_left++; 

	return (1);
}

int map_verify_min_size(t_map *map)
{
	char	*first_line;

	ft_printf("Verifying map is at least 3x3...\n");
	map->height = ft_lstsize(map->rows);
	if (map->height < 3) 
		return (0);
	first_line = (char*)map->rows->content;
	map->width = ft_strlen(first_line);
	if (map->width < 3)
		return (0);
	return (1);
}

int	map_verify_square(t_map *map)
{
	t_list	*node;
	char	*line;
	int		line_width;

	ft_printf("Verifying map is rectangular...\n");
	node = map->rows;
	while (node != NULL)
	{
		line = (char*)node->content;
		line_width = ft_strlen(line);
		ft_printf("line '%s' is %d vs %d\n", line, ft_strlen(line), map->width);
		if (line_width != map->width)
		{
			return (0);
		}
		node = node->next;
	}

	return (1);
}

int	map_verify_items(t_map *map)
{
	t_count_data	count_data;

	ft_printf("Verifying elements in map...\n");
	count_data.exit_count = 0;
	count_data.player_count = 0;
	map_loop(map, count_function, &count_data);	
	if (map->food_left == 0 
		|| count_data.exit_count != 1 
		|| count_data.player_count != 1) 
		return (0); 
	return (1);
}
