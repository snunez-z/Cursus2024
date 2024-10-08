/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:16:56 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 09:53:11 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * This module defines and initializes a structure that holds one image per
 * ASCII character from ASCII 33 (the next to space) up to '}'
 * These images will be used to write text into a MinilibX window.
 */
#ifndef FONT_H
# define FONT_H

/* The last character we have image for */
# define FONT_LAST_CHAR	'}'

/*
 * Fields:
 * "mlx" the MinilibX instance
 * "char_images" an array in which each position will contain the image for one
 *               ASCII character. The first position in the array will contain
 *               the image for character ASCII 33, the second will contain the
 *               image for character ASCII 34, and so on.
 */
typedef struct s_font
{
	void	*mlx;
	void	*char_images[FONT_LAST_CHAR - ' '];
}	t_font;

/*
 * Initializes this module by reading all the images.
 * Parameters:
 * - "mlx": The MinilibX instance, necessary to read each image
 *
 * Returns the allocated "t_font" instance or NULL if memory allocation fails.
 */
t_font	*font_load(void	*mlx);

/*
 * Return the image for a specific character.
 * Parameters:
 * - "font" the "t_font" instance (the result of "font_load")
 * - "ch" the character we want the image for.
 *
 * Returns the image or NULL if the was no valid image for the given character
 */
void	*font_get(t_font *font, char ch);

/*
 * Frees all the memory allocated in "font_load"
 * Parameters:
 * "font": the "t_font" instance to free
 */
void	font_destroy(t_font *font);

#endif
