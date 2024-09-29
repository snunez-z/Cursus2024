#include <stddef.h>
#include <stdlib.h>
#include <X11/X.h>
#include "mlx.h"

#include "game.h"
#include "images.h"
#include "map.h"
#include "util.h"

#define RATE 10000

static int close_window(game_t *game)
{
	util_write_line("Closing game");
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	game->window = NULL;
	return (0);
}

static void draw_map_cell(game_t *game, size_t x, size_t y)
{
	char	cell;
	void	*image;

	cell = map_at(game->map, y, x);
	if (cell == '1')
		image = game->images->wall;
	else if (cell == 'C')
		image = game->images->food;
	else if (cell == 'E')
		image = game->images->exit;
	else if (cell == 'P')
		image = game->images->player;
	else
		image = game->images->empty;

	mlx_put_image_to_window(game->mlx, game->window, image, IMAGE_SIZE * x, IMAGE_SIZE * y);
}

static int	draw_map(game_t *game)
{
	size_t	x;
	size_t	y;
	size_t	width;
	size_t	height;

	game->frames++;
	if (game->frames < RATE)
		return (0);
	game->frames = 0;

	util_write_line("Painting...");
	y = 0;
	width = map_get_width(game->map);
	height = map_get_height(game->map);
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			draw_map_cell(game, x, y);
			x++;
		}
		y++;
	}

	return (0);
}

static int initialized_correctly(game_t *game)
{
	return (game != NULL)
			&& (game->map != NULL)
			&& (game->images != NULL)
			&& (game->mlx != NULL)
			&& (game->window != NULL);
}

static int	key_press_hook(int key, game_t *game)
{
	if (key == 65307)
		close_window(game);
	return (0);
}


game_t	*game_create(const char *map_file_name)
{
	game_t	*game;

	util_write_line("Creating game");
	game = (game_t*)util_calloc(sizeof(game_t));
	if (game != NULL)
	{
		util_write_line("Creating map");
		game->map = map_read(map_file_name);
		if (game->map != NULL)
		{
			util_write_line("Creating window");
			game->mlx = mlx_init();
			if (game->mlx)
			{
				util_write_line("Loading images");
				game->images = images_load(game->mlx);
				game->window = mlx_new_window(game->mlx,
				                              IMAGE_SIZE * map_get_width(game->map),
				                              IMAGE_SIZE * map_get_height(game->map),
				                              "So Long");
			}
		}
	}
	if (!initialized_correctly(game))
	{
		game_destroy(game);
		return (NULL);
	}
	util_write_line("Game created");
	return (game);
}

void	game_destroy(game_t *game)
{
	util_write_line("Destroying game");
	if (!game)
		return;
	if (game->map != NULL)
		map_destroy(game->map);
	if (game->images != NULL)
		images_destroy(game->images);
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx != NULL)
		mlx_destroy_display(game->mlx);
	free(game);
}

void	game_run(game_t *game)
{
	game->frames = 0;
	if (!mlx_loop_hook(game->mlx, draw_map, game)
		|| !mlx_hook(game->window, DestroyNotify, 0, close_window, game)
		|| !mlx_key_hook(game->window, key_press_hook, game))
	{
		util_write_line("Error initializing MLX loop");
		game_destroy(game);
		return;
	}

	util_write_line("Starting game");
	mlx_loop(game->mlx);
	game_destroy(game);
	util_write_line("Exiting game");
}
