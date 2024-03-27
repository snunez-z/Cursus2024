#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>

typedef struct dstr {
	char    *buffer;
	size_t  buffer_size;
	size_t  str_len;
} dstr_t;

char	*get_next_line(int fd);
dstr_t	*dstr_create();
char	*dstr_destroy(dstr_t *pdstr);
char	*dstr_reduce(dstr_t	*pdstr);
dstr_t	*dstr_append_char(dstr_t    *dest_dstr, char ch);

#endif
