#ifndef DSTR_H
 #define DSTR_H
typedef struct s_dstr
{
	char	*buffer;
	size_t	buffer_size;
	size_t	buffer_index;
}	t_dstr;
#endif
