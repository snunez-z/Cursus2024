/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:16:56 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/08 09:31:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONT_H
# define FONT_H

# define FONT_FIRST_CHAR	'!'
# define FONT_LAST_CHAR		'}'

typedef struct s_font
{
	void	*mlx;
	// We have one image per char, starting from '!' (33) to '}' (125)
	// So we need 125 - 33 + 1 array elements
	void	*char_images[FONT_LAST_CHAR - FONT_FIRST_CHAR + 1];
}	t_font;

t_font	*font_load(void	*mlx);
void	font_destroy(t_font *font);
void	*font_get_image_for_char(t_font *font, char ch);

#endif
