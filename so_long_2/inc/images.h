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

#ifndef IMAGES_H
# define IMAGES_H

# define IMAGE_SIZE	32

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
