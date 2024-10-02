#include <stddef.h>
#include <stdlib.h>
#include <X11/X.h>
#include "ft_printf.h"
#include "mlx.h"

#include "font.h"
#include "images.h"
#include "map.h"
#include "util.h"

#include "game.h"

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

static int draw_map_cell(map_t *map, int x, int y, char cell, void *data)
{
	game_t	*game;
	void	*image;

	(void)map;
	game = (game_t*)data;
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
	return (1);
}

static int print_text(game_t *game, const char *text, int x, int y)
{
	const char	*aux;
	void	*char_image;

	aux = text;
	while(*aux)
	{
		char_image = font_get(game->font, *aux);
		if (char_image != NULL)
			mlx_put_image_to_window(game->mlx, game->window, char_image, x, y);
		x += IMAGE_SIZE;
		aux++;
	}

	return x;
}

static int print_number(game_t *game, int number, int x, int y)
{
	char	digit;
	void	*char_image;

	if (number > 9)
		x = print_number(game, number / 10, x, y);

	digit = (number % 10) + '0';
	char_image = font_get(game->font, digit);
	if (char_image != NULL)
		mlx_put_image_to_window(game->mlx, game->window, char_image, x, y);

	return x + IMAGE_SIZE;
}

static int	draw_map(game_t *game)
{
	if (!game->window)
		return (0);
	map_loop(game->map, draw_map_cell, game);
	int x = IMAGE_SIZE;
	int y = IMAGE_SIZE * map_get_height(game->map);
	x = print_text(game, "Moves: ", x, y);
	print_number(game, game->move_count, x, y);
	return (0);
}

static int initialized_correctly(game_t *game)
{
	return (game != NULL)
			&& (game->map != NULL)
			&& (game->font != NULL)
			&& (game->images != NULL)
			&& (game->mlx != NULL)
			&& (game->window != NULL);
}

static int	is_game_over(game_t *game)
{
	int food_left = map_count_chars(game->map, 'C');
	ft_printf("Food left: %d\n", food_left);
	return (game->map->at_player == 'E') && (food_left == 0);
}

static int	verify_map(game_t *game)
{

}

static int	key_press_hook(int key, game_t *game)
{
	int move_ok;

	if (key == 65307)
	{
		close_window(game);
		return (0);
	}

	if (key == KEY_UP || key == KEY_W)
		move_ok = map_move_player(game->map, 0, -1);
	else if (key == KEY_DOWN || key == KEY_S)
		move_ok = map_move_player(game->map, 0, 1);
	else if (key == KEY_RIGHT || key == KEY_D)
		move_ok = map_move_player(game->map, 1, 0);
	else if (key == KEY_LEFT || key == KEY_A)
		move_ok = map_move_player(game->map, -1, 0);
	else
		return (0);

	if (move_ok)
	{
		game->move_count++;
		if (is_game_over(game))
			close_window(game);
	}

	return (0);
}

game_t	*game_create(const char *map_file_name)
{
	game_t	*game;

	ft_printf("Creating game\n");
	game = (game_t*)util_calloc(sizeof(game_t));
	if (game != NULL)
	{
		game->move_count = 0;
		game->game_over = 0;

		ft_printf("Creating map\n");
		game->map = map_read(map_file_name);
		if (game->map != NULL)
		{
			ft_printf("Creating window\n");
			game->mlx = mlx_init();
			if (game->mlx)
			{
				game->images = images_load(game->mlx);
				game->font = font_load(game->mlx);
				game->window = mlx_new_window(game->mlx,
				                              IMAGE_SIZE * map_get_width(game->map),
				                              IMAGE_SIZE * (map_get_height(game->map) + 1),
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
	if (game->font != NULL)
		font_destroy(game->font);
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
