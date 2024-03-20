#include <stdio.h>
#include <stdlib.h>

typedef struct dstr {
    char    *buffer;
    size_t  buffer_size;
    size_t  str_len;
} dstr_t;

static void copy_buffer(char *dest, char *source, size_t len)
{
    // Implementa esta función que:
    // * Copie "len" caracteres desde "source" a "dest"
    // * Tiene que hacerlo uno a uno
    // * SIEMPRE tiene que copiar "len" caracteres SIN FIJARSE en el '\0'
}

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
    // Vamos a mejorar esta función:
    // Antes de añadir el carácter al buffer, vamos a ver si cabe o no:
    // * En el buffer caben "buffer_size" caracteres (sin contar el '\0' final)
    // * En el buffer hemos guardado ya "str_len" caracteres.
    // * Cómo sabemos si nos cabe uno más? Si "str_len" ha alcanzado a "buffer_size"
    //   significa que ya hemos ocupado todos los caracteres y, por lo tanto, tenemos
    //   que agrandar el buffer
    // Tienes que detectar si ya no caben más y, si no caben:
    // * Reservar un nuevo buffer de 10 + 1 caracteres más que el actual (el tamaño actual
    //   te lo dice el valor actual de "buffer_size"
    // * Copiar "buffer_size" + 1 (para que copie también el '\0') caracteres del buffer actual
    //   al buffer nuevo. Para eso, usa la función "copy_buffer" de más arriba
    // * Liberar el buffer antiguo
    // * Asignar al campo "buffer" el buffer nuevo
    // * Incrementar el 10 el campo "buffer_size" (porque ahora caben 10 caracteres más)

    // Después de hacer lo de arriba, ya puedes hacer esto:
    dest_dstr->buffer[dest_dstr->str_len] = ch;
    dest_dstr->buffer[dest_dstr->str_len + 1] = '\0';
    dest_dstr->str_len++;

    return (dest_dstr);
}

int main(void)
{
    dstr_t  *dstr;

    dstr = dstr_create();

    printf("%s\n", dstr->buffer);
    dstr = dstr_append_char(dstr, 'H');
    dstr = dstr_append_char(dstr, 'o');
    dstr = dstr_append_char(dstr, 'l');
    dstr = dstr_append_char(dstr, 'a');
    dstr = dstr_append_char(dstr, ' ');
    dstr = dstr_append_char(dstr, 'S');
    dstr = dstr_append_char(dstr, 'u');
    dstr = dstr_append_char(dstr, 's');
    dstr = dstr_append_char(dstr, 'h');
    dstr = dstr_append_char(dstr, 'i');
    dstr = dstr_append_char(dstr, ' ');
    dstr = dstr_append_char(dstr, 'c');
    dstr = dstr_append_char(dstr, 'o');
    dstr = dstr_append_char(dstr, 'm');
    dstr = dstr_append_char(dstr, 'o');
    dstr = dstr_append_char(dstr, ' ');
    dstr = dstr_append_char(dstr, 'e');
    dstr = dstr_append_char(dstr, 's');
    dstr = dstr_append_char(dstr, 't');
    dstr = dstr_append_char(dstr, 'a');
    dstr = dstr_append_char(dstr, 's');
    dstr = dstr_append_char(dstr, '?');
    printf("%s\n", dstr->buffer);

    dstr_destroy(dstr);
}
