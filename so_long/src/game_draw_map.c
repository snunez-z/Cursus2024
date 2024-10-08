/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:21:08 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 12:28:30 by snunez-z         ###   ########.fr       */
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

#define RATE 10000

static int	draw_map_cell(t_map_loop *map_loop)
{
	t_game	*game;
	void	*image;

	game = (t_game *)map_loop->data;
	if (map_loop->ch == '1')
		image = game->images->wall;
	else if (map_loop->ch == 'C')
		image = game->images->food;
	else if (map_loop->ch == 'E')
		image = game->images->exit;
	else if (map_loop->ch == 'P')
		image = game->images->player;
	else
		image = game->images->empty;
	mlx_put_image_to_window(game->mlx, game->window, image,
		IMAGE_SIZE * map_loop->x, IMAGE_SIZE * map_loop->y);
	return (1);
}

static int	print_text(t_game *game, const char *text, int x, int y)
{
	const char	*aux;
	void		*char_image;

	aux = text;
	while (*aux)
	{
		char_image = font_get(game->font, *aux);
		if (char_image != NULL)
			mlx_put_image_to_window(game->mlx, game->window, char_image, x, y);
		x += IMAGE_SIZE;
		aux++;
	}
	return (x);
}

static int	print_number(t_game *game, int number, int x, int y)
{
	char	digit;
	void	*char_image;

	if (number > 9)
		x = print_number(game, number / 10, x, y);
	digit = (number % 10) + '0';
	char_image = font_get(game->font, digit);
	if (char_image != NULL)
		mlx_put_image_to_window(game->mlx, game->window, char_image, x, y);
	return (x + IMAGE_SIZE);
}

int	game_draw_map(t_game *game)
{
	int	x;
	int	y;
	int	move_count;

	if (!game->window)
		return (0);
	map_loop(game->map, draw_map_cell, game);
	x = IMAGE_SIZE;
	y = IMAGE_SIZE * game->map->height;
	move_count = map_get_move_count(game->map);
	x = print_text(game, "Moves: ", x, y);
	print_number(game, move_count, x, y);
	return (0);
}
