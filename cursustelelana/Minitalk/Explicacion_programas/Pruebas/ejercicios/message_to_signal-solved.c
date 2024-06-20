#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Haz esta función:
// Recibe un mensaje como parámetro. Por ejemplo: "Hola"
// Tiene que reservar (malloc) un array para tantos int's como señales tiene que enviar
// para ese mensaje.
// Cuántas señales tiene que enviar? Pues 8 señales por cada carácter (o sea, 8x4=32 señales)
// más otras 8 para el \0 (o sea 32+8=40)
// Por supuesto, el número de señales (o sea, el tamaño del malloc) depende del número de
// caracteres del mensaje.
// Si falla la reserva de memoria, tiene que retornar NULL para indicar error
// Después de reservar memoria para el array, tiene que rellenarlo con las señales que tiene
// que enviar.
// Para ello, tiene que ver los bits de cada carácter y poner en el array SIGUSR1 si el bit es
// un cero y SIGUSR2 si el bit es un 1
// Por ejemplo, si el carácter es la "H":
// * H => ASCII 72 => Binario 01001000
// * Por lo tanto, en las primeras 8 posiciones del array, tiene que poner:
// +-------+-------+-------+-------+-------+-------+-------+-------+
// |SIGUSR1|SIGUSR2|SIGUSR1|SIGUSR1|SIGUSR2|SIGUSR1|SIGUSR1|SIGUSR1|
// +-------+-------+-------+-------+-------+-------+-------+-------+

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
        // Para no tener que estar poniendo message[char_index] todo el rato (es un coñazo)
        // usamos esta variable. Así escribo menos y me canso menos
        char ch = message[char_index];

        // Vamos a usar el método de la máscara para sacar los bits
        // Recuerda: Empezamos con la máscara en 1 (bit de la derecha) y vamos pasando a la
        //           izquierda multiplicando por 2. Cuantas veces? 8, por que hay 8 bits
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

        // Pasamos al siguiente carácter
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

