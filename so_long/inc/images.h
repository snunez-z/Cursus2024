/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:18:15 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/08 09:31:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * This module defines and initializes a structure that holds the images the
 * will use.
 */

#ifndef IMAGES_H
# define IMAGES_H

/* Size (width and height) of the images, in pixels */
# define IMAGE_SIZE	32

/*
 * Fields:
 * "mlx" the MinilibX instance
 * "empty"  the image for an empty cell in the map
 * "wall"   the image for a wall in the map
 * "player" the image for the player
 * "food"   the image for food
 * "exit"   the image for the exit
 */
typedef struct s_images
{
	void	*mlx;
	void	*empty;
	void	*wall;
	void	*player;
	void	*food;
	void	*exit;
}	t_images;

t_images	*images_load(void	*mlx);
void		images_destroy(t_images *images);

#endif
