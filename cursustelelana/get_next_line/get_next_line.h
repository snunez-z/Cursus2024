#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>

typedef struct dstr
{
	char	*buffer;
	size_t	buffer_size;
	size_t	str_len;
}	t_dstr;

char	*get_next_line(int fd);
t_dstr	*dstr_create(void);
char	*dstr_destroy(t_dstr *pdstr);
char	*dstr_reduce(t_dstr *pdstr);
t_dstr	*dstr_append_char(t_dstr *dest_dstr, char ch);

#endif
