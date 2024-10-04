/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:17:55 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 09:57:02 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "font.h"
# include "images.h"
# include "map.h"

typedef struct game_s
{
	t_map		*map;
	t_images	*images;
	t_font		*font;
	int			move_count;
	int			game_over;
	void		*mlx;
	void		*window;
	int			frames;
}	t_game;

t_game	*game_create(const char *map_file_name);
void	game_destroy(t_game *game);
void	game_run(t_game *game);

#endif
