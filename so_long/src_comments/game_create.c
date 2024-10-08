/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:21:08 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/08 11:45:17 by snunez-z         ###   ########.fr       */
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

static void	create_map(t_game *game, const char *map_file_name)
{
	ft_printf("Creating map\n");
	game->map = map_read(map_file_name);
	if (game->map != NULL)
	{
		ft_printf("Creating window\n");
		game->mlx = mlx_init();
		if (game->mlx)
		{
			game->images = images_load(game->mlx); // Inicializa todo y lo guarda en game 
			game->font = font_load(game->mlx);
			game->window = mlx_new_window(game->mlx,
			                              IMAGE_SIZE * game->map->width,
			                              IMAGE_SIZE * (game->map->height + 1),
			                              "So Long");
		}
	}
}

static int	verify_map_fits_into_screen(t_game *game)
{
	int	width;
	int	height;

	mlx_get_screen_size(game->mlx, &width, &height); // es la mlx la que manejea si cabe en la pantalla 
	width = width / IMAGE_SIZE;
	height = height / IMAGE_SIZE;
	if ((width < game->map->width) || (height < game->map->height))// paso el puntero a la direccion de memoria donde quiero guardarlo.
	{
		ft_printf("Error\nMap doesn't fit into screen\n");
		return (0);
	}
	return (1);
}

t_game	*game_create(const char *map_file_name)
{
	t_game	*game;

	ft_printf("Creating game\n");
	game = (t_game *)util_calloc(sizeof(t_game));//Reserva memoria para la estructura 
	if (!game)
		return (NULL);
	create_map(game, map_file_name); // Se crean todos los modulos que necesita 
	if (!game->map || !game->font || !game->images || !game->mlx
		|| !game->window || !verify_map_fits_into_screen (game))
	{
		game_destroy(game);
		return (NULL);
	}
	ft_printf("Game created\n");
	return (game);
}
