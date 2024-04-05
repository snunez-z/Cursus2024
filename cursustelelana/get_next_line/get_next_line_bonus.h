// Pon las cabeceras propias de un .h

// Declara la constante para cuántos ficheros simultaneos podemos tratar

// Necesitamos un struct gnl_bonus porque para cada fichero distinto del que
// queremos leer, necesitamos los tres datos que teníamos como static en la
// parte no bonus: el buffer, cuánto está ocupado y qué carácter hemos retornado
// Además, necesitamos un campo más para identificar a qué fd pertenece esta
// estructura
#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define MAX_OP_FD 10240

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>


typedef struct gnl_bonus
{
	char				buffer [BUFFER_SIZE];
	int					buffer_size;
	int					buffer_index;
	int					fd;
}	t_gnl_bonus;

typedef struct open_files
{
	t_gnl_bonus	buffer[MAX_OP_FD];
	size_t	fd_num;

} t_open_files;

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
