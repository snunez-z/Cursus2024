#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dos bucles anidados es feo. Es de mal programador
// Vamos a sacar el de dentro a una función que rellene ocho posiciones del array
// con los bits de un char
// EL ARRAY YA ESTA CREADO No hay que hacer malloc ni nada

void fill_signals_for_char(int *array, char ch, int array_index)
{
    int mask = 1;
    int bit_count = 0;
    while(bit_count < 8)
    {
        // Si la máscara dice que hay un 0, ponemos SIGUSR1 en el array. Sino, ponemos SIGUSR2
        if ((ch & mask) == 0)
            array[array_index] = SIGUSR1;
        else
            array[array_index] = SIGUSR2;

        // Y ahora pasamos a la siguiente posición del array
        // y la siguiente posición de la máscara
        array_index++;
        mask = mask * 2;
        bit_count++;
    }
}

int* message_to_signals(const char *message)
{
    // Cuantos caracteres hay que codificar: tantos como diga "strlen" + 1 por el \0
    int char_count = strlen(message) + 1;
    // En el array, necesitamos 8 posiciones (8 señales) por cada carácter
    int array_size = char_count * 8;
    int *array = malloc(array_size * sizeof(int));
    if (array == NULL)
        return (NULL);

    // Vamos a necesitar do bucles:
    // Uno que recorra cada carácter
    // Otro para que recorra cada uno de los 8 bits de cada carácter
    int array_index = 0;
    int char_index = 0;
    while(char_index < char_count)
    {
        fill_signals_for_char(array, message[char_index], array_index);
        // fill_signals_for_char ha rellenado 8 bits, así es que tenemos que sumar 8
        // a "array_index"
        array_index = array_index +8;
        char_index++;
    }

    return array;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("usage %s <message>\n", argv[0]);
        return (1);
    }

    int *signals = message_to_signals(argv[1]);
    if (signals == NULL)
    {
        printf("Error reserving memory for the signals\n");
        return (1);
    }

    // Cuantos elementos habrá en el array "signals"?
    // Pues 8 elementos por cada carácter más otros 8 para el \0 final
    int num_signals = (strlen(argv[1]) * 8) + 8;
    int n = 0;
    while (n < num_signals)
    {
        if (signals[n] == SIGUSR1)
            printf("SIGUSR1, ");
        else
            printf("SIGUSR2, ");

        n++;
    }
    printf("\n");

    // HIGIENEEEE!!!! Memory leaks suck!
    free(signals);
    return (0);
}

