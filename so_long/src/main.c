/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:22:15 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 12:40:00 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "util.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
	{
		ft_printf("Error\nUsage: %s <path_to_map_file>\n");
		return (1);
	}
	game = game_create(argv[1]);
	if (game != NULL)
		game_run(game);
	return (0);
}
