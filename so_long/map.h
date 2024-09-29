#ifndef MAP_H
 #define MAP_H

#include "list.h"

typedef list_t map_t;

map_t	*map_read(const char *file_name);
void	map_destroy(map_t *map);
void	map_write(map_t *map, int fd);
size_t	map_get_width(map_t *map);
size_t	map_get_height(map_t *map);
char	map_at(map_t *map, size_t x, size_t y);

#endif