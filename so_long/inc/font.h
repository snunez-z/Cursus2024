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

#ifndef FONT_H
# define FONT_H

# define FONT_LAST_CHAR	'}'

typedef struct s_font
{
	void	*mlx;
	void	*char_images[FONT_LAST_CHAR - ' '];
}	t_font;

t_font	*font_load(void	*mlx);
void	*font_get(t_font *font, char ch);
void	font_destroy(t_font *font);

#endif
