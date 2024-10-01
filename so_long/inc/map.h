#ifndef MAP_H
 #define MAP_H

#include "list.h"

typedef struct map_s
{
	list_t *rows;
	size_t	player_x;
	size_t	player_y;
	char	at_player;
}	map_t;

map_t	*map_read(const char *file_name);
void	map_destroy(map_t *map);
void	map_write(map_t *map, int fd);
size_t	map_get_width(map_t *map);
size_t	map_get_height(map_t *map);
char	map_at(map_t *map, size_t x, size_t y);
void	map_move_player(map_t *map, int inc_x, int inc_y);
void	map_loop(map_t *map, int (*fn)(map_t*, size_t, size_t, char, void*), void *data);

#endif