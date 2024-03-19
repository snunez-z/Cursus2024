#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>

char	*get_next_line(int fd);
int		read_one_char(int fd, char	*buffer);
char	*ft_realloc(char *old_buffer, size_t *buffer_size);
char	*ft_reduce(char *buffer, size_t buffer_size);

#endif
