#include "map.h"

void	map_loop(t_map *map, int (*fn)(t_map_loop *), void *data)
{
	t_map_loop	map_loop; 

	map_loop.map = map; 
	map_loop.data = data; 
	map_loop.y = 0; 
	while (map_loop.y < map->height)
	{
		map_loop.x = 0; 
		while (map_loop.x < map->width) 
		{
			map_loop.ch = map_at(map, map_loop.x, map_loop.y, 0); 
			if (fn(&map_loop) == 0) 
				return ;
			map_loop.x++; 
		}
		map_loop.y++;
	}
}
