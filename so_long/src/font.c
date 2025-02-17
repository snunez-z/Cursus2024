/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:20:31 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/20 20:03:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"
#include "font.h"
#include "util.h"

#define FONT_SIZE	32
#define FILE_NAME_SIZE	25

static void	copy_char_file_name(char ch, char *buffer)
{
	ft_strlcpy(buffer, "textures/font/", FILE_NAME_SIZE);
	buffer[14] = (ch / 100) + '0';
	buffer[15] = ((ch % 100) / 10) + '0';
	buffer[16] = (ch % 10) + '0';
	buffer[17] = '\0';
	ft_strlcat(buffer, ".xpm", FILE_NAME_SIZE);
}

t_font	*font_load(void	*mlx)
{
	t_font	*font;
	char	file_name[FILE_NAME_SIZE + 1];
	char	ch;
	int		index;

	ft_printf("Loading font images\n");
	font = (t_font *) util_calloc(sizeof(t_font));
	if (!font)
		return (NULL);
	font->mlx = mlx;
	ch = FONT_FIRST_CHAR;
	while (ch <= FONT_LAST_CHAR)
	{
		copy_char_file_name(ch, file_name);
		index = (ch - FONT_FIRST_CHAR);
		font->char_images[index] = util_load_image(mlx, file_name);
		ch++;
	}
	return (font);
}

void	font_destroy(t_font *font)
{
	char	ch;
	int		index;

	ft_printf("Destroying font...\n");
	ch = FONT_FIRST_CHAR;
	while (ch <= FONT_LAST_CHAR)
	{
		index = (ch - FONT_FIRST_CHAR);
		util_destroy_image(font->mlx, font->char_images[index]);
		ch++;
	}
	free(font);
}

void	*font_get_image_for_char(t_font *font, char ch)
{
	int	pos;

	if (ch < FONT_FIRST_CHAR || ch > FONT_LAST_CHAR)
		return (NULL);
	pos = ch - FONT_FIRST_CHAR;
	return (font->char_images[pos]);
}
