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
    pdstr->buffer = malloc(11 * sizeof(char));
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
    int index;
    int index2;
    dstr_t  *dstr;

    if (argc < 2)
    {
        printf("Pasa como parámetro al menos una palabra!!!\n");
        return (-1);
    }

    dstr = dstr_create();
    
    // Cambia el programa anterior para, no sólo añadir cada carácter del primer
    // parámetro, sino de todos los parámetros que pasen
    index = 1; // Porque el índice 0 no es un parámetro, es el nombre del programa
     while (index < argc)
    {
        index2 = 0;
        while(argv[index][index2]!= 0)
        {
            dstr = dstr_append_char(dstr, argv[index][index2]);
            index2++;
        }
        dstr = dstr_append_char(dstr, ' ');
    index++;
    }    
    // Después de hacerlo, te debería salir la concatenación de todos los parámetros
    // que pases... ocupen lo que ocupen!!! sin más límite que la memoria del ordenador
    printf("%s\n", dstr->buffer);
    dstr_destroy(dstr);
    return (0);
}


