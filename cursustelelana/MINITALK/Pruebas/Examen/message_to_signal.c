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
    int num_chars;
    int num_bits ;
    int *buffer;
    int mask;
    int char_index;
    int buffer_index;
    
    num_chars = strlen (message) + 1;
    num_bits = num_chars * 8;
    buffer = malloc ( num_bits * sizeof(int));
    if (buffer == NULL)
        return (NULL);
    char_index = 0;
    buffer_index= 0;
    while (char_index < num_chars)
    {
        mask = 128;
        num_bits = 0;
        while ( num_bits < 8 )
        {
            if((message [char_index] & mask) == 0)
                buffer [buffer_index] = SIGUSR1;
            else
                buffer [buffer_index] = SIGUSR2;
            buffer_index++;
            mask = mask / 2;
            num_bits++;
        }
        char_index++;
    }
    return (buffer);
}   
    
 int main(int argc, char **argv)
{
    int *signals;
    int num_signals;
    int index;

    if (argc < 2)
    {
        printf("sin mensaje no hay respuesta\n");
        return (1);
    }

    signals = message_to_signals (argv[1]);
    if (signals == NULL)
    {
        printf(" Error reserving memory\n");
        return (1);
    }
    num_signals = (strlen (argv[1]) * 8) + 8;
    index = 0;
    while (index < num_signals)
    {
        if (signals [index] == SIGUSR1)
            printf( "SIGUSR1, ");
        else
            printf("SIGUSR2, ");
        index++;
    }
    printf("\n");
    free (signals);
    return (0);
}    



    

 












