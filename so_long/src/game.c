/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:21:08 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/20 17:03:14 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#define KEY_ESC	65307
#define KEY_W	119
#define KEY_A	97
#define KEY_S	115
#define KEY_D	100
#define KEY_UP	65362
#define KEY_DOWN	65364
#define KEY_LEFT	65361
#define KEY_RIGHT	65363

static int	close_window(t_game *game)
{
	ft_printf("Closing game\n");
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	game->window = NULL;
	return (0);
}

static int	key_press_hook(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		close_window(game);
		return (0);
	}
	if (key == KEY_UP || key == KEY_W)
		map_move_player(game->map, 0, -1);
	else if (key == KEY_DOWN || key == KEY_S)
		map_move_player(game->map, 0, 1);
	else if (key == KEY_RIGHT || key == KEY_D)
		map_move_player(game->map, 1, 0);
	else if (key == KEY_LEFT || key == KEY_A)
		map_move_player(game->map, -1, 0);
	if (map_is_over(game->map))
		close_window(game);
	return (0);
}

void	game_destroy(t_game *game)
{
	ft_printf("Destroying game\n");
	if (!game)
		return ;
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	if (game->font != NULL)
		font_destroy(game->font);
	if (game->images != NULL)
		images_destroy(game->images);
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map != NULL)
		map_destroy(game->map);
	free (game);
}

void	game_run(t_game *game)
{
	if (!mlx_loop_hook(game->mlx, game_draw_map, game)
		|| !mlx_hook(game->window, DestroyNotify, 0, close_window, game)
		|| !mlx_hook(game->window, KeyPress, KeyPressMask,
			key_press_hook, game))
	{
		ft_printf("Error\nError initializing MLX loop\n");
		game_destroy(game);
		return ;
	}
	ft_printf("Starting game\n");
	mlx_loop(game->mlx);
	game_destroy(game);
	ft_printf("Exiting game\n");
}
