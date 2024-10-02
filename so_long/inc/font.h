#ifndef FONT_H
 #define FONT_H

 #define FONT_LAST_CHAR	'}'

typedef struct font_s
{
	void	*mlx;
	void	*char_images[FONT_LAST_CHAR - ' '];
} font_t;

font_t	*font_load(void	*mlx);
void	*font_get(font_t *font, char ch);
void	font_destroy(font_t *font);

#endif