#include <stdio.h>
#include <stdlib.h>

typedef struct dstr {
    char    *buffer;
    size_t  buffer_size;
    size_t  str_len;
} dstr_t;

dstr_t  *dstr_create()
{
    dstr_t  *pdstr;

    pdstr = malloc(1 * sizeof(dstr));
    pdstr->buffer = malloc(11 * sizeof(char)));
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
    // Implementa esta función:
    // Añade el carácter "ch" al buffer. Para eso tienes que hacer dos cosas:
    // 1. Copiar el carácter "ch" a la primera posición libre del buffer
    //    Cuál es la última posición libre? Pues, si el campo "str_len" es cero, significa
    //    que la primera posición libre es esa, la cero.
    //    Si "str_len" es 1, significa que hay un carácter en el buffer (en la posición cero),
    //    por lo tanto la primera posición libre es la 1
    //    Papel y lápiz... parece que "str_len" te dice no sólo la longitud de la cadena que
    //    tienes en "buffer" sino la primera posición libre
    //    Tiene sentido: Si tengo 6 caracteres, la primera posición "libre" es la 6 (porque de
    //    la cero a la 5 están ocupadas)
    // 2. Poner un '\0' después de "ch"
    // 3. Incrementa el valor del campo "str_len", porque hemos añadido un carácter al buffer


    // Más adelante por qué es bueno retornar "dest_dstr"
    return (dest_dstr);
}

int main(void)
{
    dstr_t  *dstr;

    dstr = dstr_create();

    printf("%s\n", dstr->buffer);
    dstr = dstr_append_char(dstr, 'H');
    printf("%s\n", dstr->buffer);
    dstr = dstr_append_char(dstr, 'o');
    printf("%s\n", dstr->buffer);
    dstr = dstr_append_char(dstr, 'l');
    printf("%s\n", dstr->buffer);
    dstr = dstr_append_char(dstr, 'a');
    printf("%s\n", dstr->buffer);

    dstr_destroy(dstr);
}
