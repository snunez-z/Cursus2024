#ifndef DSTR_H
 #define DSTR_H

typedef struct s_dstr
{
	char	*buffer;
	size_t	buffer_size;
	size_t	buffer_index;
}	dstr_t;

dstr_t	*dstr_create();
void	dstr_destroy(dstr_t *dstr);
char	dstr_char_at(dstr_t *dstr, size_t pos);
char	dstr_set_char_at(dstr_t *dstr, size_t pos, char ch);
int	dstr_append_char(dstr_t *dstr, char ch);
size_t	dstr_length(dstr_t *dstr);
void	dstr_write(dstr_t *dstr, int fd, int new_line);

#endif
