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

