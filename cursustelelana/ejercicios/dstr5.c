#include <stdio.h>
#include <stdlib.h>

typedef struct dstr {
    char    *buffer;
    size_t  buffer_size;
    size_t  str_len;
} dstr_t;

static void copy_buffer(char *dest, char *source, size_t len)
{
    size_t index;

    index = 0;
    while(index < len)
    {
        dest[index] = source[index];
        index++;
    }
}

dstr_t  *dstr_create()
{
    dstr_t  *pdstr;

    pdstr = malloc(1 * sizeof(dstr_t));
    if (pdstr == NULL)
        return (NULL);
    pdstr->buffer = malloc(11 * sizeof(char));
    if (pdstr == NULL)
    {
        free (NULL);
        return (NULL);
    }
    pdstr->buffer[0] = '\0';
    pdstr->buffer_size = 10;
    pdstr->str_len = 0;
    return (pdstr);
}

dstr_t  *dstr_destroy(dstr_t *pdstr)
{
    free(pdstr->buffer);
    free(pdstr);
    return (NULL);
}

dstr_t  *dstr_append_char(dstr_t    *dest_dstr, char ch)
{
    char *new_buffer;

    if (dest_dstr->str_len >= dest_dstr->buffer_size)
    {
        new_buffer = malloc((dest_dstr->buffer_size + 10 + 1) * sizeof(char)); 
        copy_buffer(new_buffer, dest_dstr->buffer, dest_dstr->buffer_size + 1);
        free(dest_dstr->buffer);
        dest_dstr->buffer = new_buffer;
        dest_dstr->buffer_size = dest_dstr->buffer_size + 10;
    }

    dest_dstr->buffer[dest_dstr->str_len] = ch;
    dest_dstr->buffer[dest_dstr->str_len + 1] = '\0';
    dest_dstr->str_len++;

    return (dest_dstr);
}

int main(int argc, char **argv)
{
    dstr_t  *dstr;
    int index;

    if (argc < 2)
    {
        printf("Pasa como parámetro al menos una palabra!!!\n");
        return (-1);
    }
    index = 0;
    dstr = dstr_create();

    // printf("%s\n", argv[1]);
    // printf("%c\n", argv[1][0]);
    // printf("%c\n", argv[1][1]);
    // printf("%c\n", argv[1][2]);
    while (argv[1][index] != '\0')
    {
        dstr = dstr_append_char (dstr, argv[1][index]);
        index++;
    }    
    
    // dstr = dstr_append_char (dstr, ch);
    // Lo que vamos a hacer es añadir carácter a carácter cada uno de los caracteres del primer
    // parámetro que pasen al programa (argv[1])
    // Para añadir un carácter, ya sabes, usa "dstr_append_char"

    // Después de hacerlo, te debería salir la palabra que has pasado como parámetro
    // La gracia de esto es que la palabra puede ser tan larga como quieras :)
    printf("%s\n", dstr->buffer);
    dstr_destroy(dstr);
    return (0);
}

