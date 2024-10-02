#ifndef GAME_H
 #define GAME_H

#include "font.h"
#include "images.h"
#include "map.h"

typedef struct game_s
{
	map_t	*map;
	images_t	*images;
	font_t	*font;
	int	move_count;
	int	game_over;
	void	*mlx;
	void	*window;
	int	frames;
} game_t;

game_t	*game_create(const char *map_file_name);
void	game_destroy(game_t *game);
void	game_run(game_t *game);

#endif