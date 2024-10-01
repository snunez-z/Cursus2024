#ifndef MAP_H
 #define MAP_H

#include "list.h"

typedef struct map_s
{
	list_t *rows;
	int	player_x;
	int	player_y;
	char	at_player;
}	map_t;

map_t	*map_read(const char *file_name);
void	map_destroy(map_t *map);
void	map_write(map_t *map, int fd);
int	map_get_width(map_t *map);
int	map_get_height(map_t *map);
char	map_at(map_t *map, int x, int y);
int	map_move_player(map_t *map, int inc_x, int inc_y);
int	map_count_chars(map_t *map, char ch);
void	map_loop(map_t *map, int (*fn)(map_t*, int, int, char, void*), void *data);

#endif