/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:21:29 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 12:34:31 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "mlx.h"
#include "images.h"
#include "util.h"

t_images	*images_load(void *mlx)
{
	t_images	*images;

	ft_printf("Loading images\n");
	images = (t_images *) util_calloc(sizeof(t_images));
	if (!images)
		return (NULL);
	images->mlx = mlx;
	images->empty = util_load_image(mlx, "images/empty.xpm");
	images->wall = util_load_image(mlx, "images/wall.xpm");
	images->player = util_load_image(mlx, "images/player.xpm");
	images->food = util_load_image(mlx, "images/food.xpm");
	images->exit = util_load_image(mlx, "images/exit.xpm");
	if (!images->empty || !images->wall || !images->player
		|| !images->food || !images->exit)
	{
		images_destroy(images);
		return (NULL);
	}
	return (images);
}

void	images_destroy(t_images *images)
{
	util_destroy_image(images->mlx, images->empty);
	util_destroy_image(images->mlx, images->wall);
	util_destroy_image(images->mlx, images->player);
	util_destroy_image(images->mlx, images->food);
	util_destroy_image(images->mlx, images->exit);
	free(images);
}
