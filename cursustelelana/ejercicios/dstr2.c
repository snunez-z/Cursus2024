#include <stdio.h>
#include <stdlib.h>

typedef struct dstr {
    char    *buffer;
    size_t  buffer_size;
    size_t  str_len;
} dstr_t;

dstr_t  *dstr_append_char(dstr_t    *dest_dstr, char ch)
{
    // Implementa esta función. Por ahora sólo:
    // Si "dest_dstr" es NULL:
    // * Haz malloc de un struct dstr (o dstr_t, que son los mismo)
    // * Haz malloc de un buffer para 10 caracteres + 1 (para el '\0'), o sea 11 chars y
    //   asígnaselo al campo "buffer"
    // * Inicializa el campo "buffer_size" a 10 ("buffer_size" va a tener cuantos caracteres
    //   caben, por lo que aunque hemos reservado 11, como uno está reservado para el '\0',
    //   sólo caben 10)
    // * Inicializa el campo "str_len" a cero (porque por ahora no hemos copiado nada el buffer)
    // * En la primera posición de "buffer" por el carácter "ch" y en la segunda pon el '\0'
    // * Como ahora en el buffer hemos puesto un carácter, cambia "str_len" a 1
    // * Retorna el puntero al dstr_t que has hecho malloc en el primer paso.
}

int main(void)
{
    dstr_t  *dstr;

    dstr = NULL;
    dstr = dstr_append_char(dstr, 'H');
    printf("%s\n", dstr->buffer);
}
