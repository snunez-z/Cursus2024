/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:20:31 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 11:32:05 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"
#include "font.h"
#include "util.h"

#define FILE_NAME_SIZE	100

/*
 * Returns the index inside the "char_images" array where the image for a
 * specific character is stored into. For example, '!' (ASCII 33) is stored
 * in the first position of the array, '"' (ASCII 34) is stored in the
 * second position of the array, and so on.
 */
static int	get_char_index(char ch)
{
	return (ch - ' ' - 1);
}

/*
 * The name of the file containing each character uses a specific name format:
 * "./font/---.xpm", where "---" is the three-digit number of the ASCII value
 * of the character.
 * This function stores into "buffer" the name of the file where the image
 * for character "ch" is stored into.
 * For example, for '!' (ASCII 33), it will store "./font/033.xpm" into "buffer"
 */
static char	*get_char_file_name(char ch, char *buffer) // ./font/***.xpm
{
	ft_strlcpy(buffer, "./font/", FILE_NAME_SIZE);
	// Hundreds
	buffer[7] = (ch / 100) + '0';
	// Tenths
	buffer[8] = ((ch % 100) / 10) + '0';
	// Units
	buffer[9] = (ch % 10) + '0';
	// Always terminate strings with '\0' :)
	buffer[10] = '\0';
	ft_strlcat(buffer, ".xpm", FILE_NAME_SIZE);
	return (buffer);
}

t_font	*font_load(void	*mlx)
{
	t_font	*font;
	char	buffer[FILE_NAME_SIZE + 1];
	char	ch;
	int		index;

	ft_printf("Loading font images\n");
	font = (t_font *) util_calloc(sizeof(t_font));
	if (!font)
		return (NULL);
	font->mlx = mlx;
	ch = ' ' + 1;
	while (ch <= FONT_LAST_CHAR)
	{
		index = get_char_index(ch);
		font->char_images[index] = util_load_image(mlx,
			get_char_file_name(ch, buffer));
		ch++;
	}
	return (font);
}

void	font_destroy(t_font *font)
{
	char	ch;

	ft_printf("Destroying font...\n");
	ch = ' ' + 1;
	while (ch <= FONT_LAST_CHAR)
	{
		util_destroy_image(font->mlx, font->char_images[get_char_index(ch)]);
		ch++;
	}
	free(font);
}

void	*font_get(t_font *font, char ch)
{
	int	pos;

	pos = get_char_index(ch);
	if (pos < 0 || pos >= get_char_index(FONT_LAST_CHAR))
		return (NULL);
	if (font->char_images[pos] == NULL)
		ft_printf("No image for '%c'\n", ch);
	return (font->char_images[pos]);
}
