#include <stddef.h>
#include <stdlib.h>
#include <X11/X.h>
#include "ft_printf.h"
#include "mlx.h"

#include "game.h"
#include "images.h"
#include "map.h"
#include "util.h"

#define RATE 10000
#define KEY_ESC	65307
#define KEY_W	119
#define KEY_A	97
#define KEY_S	115
#define KEY_D	100
#define KEY_UP	65362
#define KEY_DOWN	65364
#define KEY_LEFT	65361
#define KEY_RIGHT	65363

static int close_window(game_t *game)
{
	ft_printf("Closing game\n");
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	game->window = NULL;
	return (0);
}

static void draw_map_cell(game_t *game, size_t x, size_t y)
{
	char	cell;
	void	*image;

	cell = map_at(game->map, x, y);
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

	ft_printf("Painting\n");
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
	else if (key == KEY_UP || key == KEY_W)
		map_move_player(game->map, 0, -1);
	else if (key == KEY_DOWN || key == KEY_S)
		map_move_player(game->map, 0, 1);
	else if (key == KEY_RIGHT || key == KEY_D)
		map_move_player(game->map, 1, 0);
	else if (key == KEY_LEFT || key == KEY_A)
		map_move_player(game->map, -1, 0);
	return (0);
}


game_t	*game_create(const char *map_file_name)
{
	game_t	*game;

	ft_printf("Creating game\n");
	game = (game_t*)util_calloc(sizeof(game_t));
	if (game != NULL)
	{
		ft_printf("Creating map\n");
		game->map = map_read(map_file_name);
		if (game->map != NULL)
		{
			ft_printf("Creating window\n");
			game->mlx = mlx_init();
			if (game->mlx)
			{
				ft_printf("Loading images\n");
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
	ft_printf("Game created\n");
	return (game);
}

void	game_destroy(game_t *game)
{
	ft_printf("Destroying game\n");
	if (!game)
		return;
	if (game->map != NULL)
		map_destroy(game->map);
	if (game->images != NULL)
		images_destroy(game->images);
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

void	game_run(game_t *game)
{
	game->frames = 0;
	if (!mlx_loop_hook(game->mlx, draw_map, game)
		|| !mlx_hook(game->window, DestroyNotify, 0, close_window, game)
		|| !mlx_hook(game->window, KeyPress, KeyPressMask, key_press_hook, game))
	{
		ft_printf("Error\nError initializing MLX loop\n");
		game_destroy(game);
		return;
	}

	ft_printf("Starting game\n");
	mlx_loop(game->mlx);
	game_destroy(game);
	ft_printf("Exiting game\n");
}
