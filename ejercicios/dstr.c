#include <stdio.h>
#include <stdlib.h>

typedef struct dstr
{
    char    *buffer;
    size_t  buffer_size;
    size_t  str_len;
}dstr_t;

// Define una estructura llamada dstr (struct dstr) que tenga tres campos:
// * Un campo "buffer" (char*)
// * Un campo llamado "buffer_size" que usaremos para guardar el tamaño del buffer (size_t)
// * Un campo llamado "str_len" que usaremos para guardar cúantos caracteres hemos guardado
//   en el buffer (size_t)
// "dstr" es la abreviatura de "dynamic string"
// Define un alias para el struct dstr: dstr_t

int main(void)
{
    // Con que este main compile, es suficiente para este ejercicio
    dstr_t  *dstr;
    return (0);
    
}
//estas funciones permiten crear, manipular y destruir cadenas dinámicas representadas 
//por la estructura dstr_t, gestionando la asignación y liberación de memoria de manera dinámica según sea necesario.