#include <stddef.h>
#include "ft_printf.h"
#include "dstr.h"
#include "list.h"
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

int	map_verify_square(t_map *map)
{
	int	index;
	int row_width;

	ft_printf("Verifying map is rectangular...\n");
	map->height = list_size(map->rows);
	if (map->height < 3) 
		return (0);
	map->width = dstr_length(list_get(map->rows, 0));
	if (map->width < 3)
		return(0);
	index = 1;
	while (index < map->height)
	{
		row_width = (int)dstr_length(list_get(map->rows, index));
		if (row_width != map->width) 
			return (0);
		index++;
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
