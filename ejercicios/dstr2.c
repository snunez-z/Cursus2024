#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct dstr {
    char    *buffer;
    size_t  buffer_size;
    size_t  str_len;
} dstr_t;

dstr_t  *dstr_create()
{
    // Implementa esta función:
    // * Haga malloc de un struct dstr (o dstr_t, que son los mismo)
    // * Haga malloc de un buffer para 10 caracteres + 1 (para el '\0'), o sea 11 chars y
    //   asígnaselo al campo "buffer"
    // * Inicializa el campo "buffer_size" a 10 ("buffer_size" va a tener cuantos caracteres
    //   caben, por lo que aunque hemos reservado 11, como uno está reservado para el '\0',
    //   sólo caben 10)
    // * Inicializa el campo "str_len" a cero (porque por ahora no hemos copiado nada el buffer)
    // * Ponga un '\0' en la primera posición del buffer (con esto conseguimos que en el buffer haya
    //   una cadena vacía)
    // * Retorne el puntero al dstr_t que has hecho malloc en el primer paso.
    dstr_t  *name;

    name = malloc (1 * sizeof (dstr_t));
    if (name == NULL)
        return (NULL);
    name->buffer = malloc(11 * sizeof (char));
    if (name->buffer == NULL)
    {
        free (name);
        return (NULL);
    }
    name->buffer_size = 10;
    name->str_len = 0;
    name->buffer[0] = '\0';
    return (name);
}

dstr_t  *dstr_destroy(dstr_t *dstr)
{
    free(dstr->buffer);
    free(dstr);
    return (NULL);
    
    // Implementa esta función que:
    // 1. Libere el campo "buffer"
    // 2. Libere el propio "dstr"
    // 3. Retorne NULL (ya veremos para qué es útil)
}

int main(void)
{
    dstr_t  *dstr;

    dstr = NULL;
    dstr = dstr_create();
    printf("%s\n", dstr->buffer);
    dstr_destroy(dstr);
    return (0);
}
