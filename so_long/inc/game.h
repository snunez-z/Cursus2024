#ifndef GAME_H
 #define GAME_H

#include "images.h"
#include "map.h"
typedef struct game_s
{
	map_t	*map;
	images_t	*images;
	void	*mlx;
	void	*window;
	size_t	frames;
} game_t;

game_t	*game_create(const char *map_file_name);
void	game_destroy(game_t *game);
void	game_run(game_t *game);

#endif