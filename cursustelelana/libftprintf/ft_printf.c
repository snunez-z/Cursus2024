#include <stdio.h>
#include <stdarg.h>

// retorna un int para poder controlar los fallos, si retorna un int positivo es que tuvo exito.
int	ft_printf(char const *format, ...)
{
// Inicializar el puntero de argumentos variables
    va_list args;
    va_start(args, format);

	// Variable para contar los caracteres impresos
    int count = 0;
while ( const char *p == format && *p != '\n')
	p++;
if (*p == '%') 
{  // Avanzar al siguiente carácter
	++p;
  // Si es una cadena de caracteres, obtenemos el valor del argumento
 	char *str = va_arg(args, char*);
 	int length = 0;
 	while (str[length] != '\0')
   	{
		++length;
    }
		write(STDOUT_FILENO, str, length);
        count += length;
        break;
}
                // Otros casos de formato pueden ser añadidos según sea necesario
            }
        } else {
            // Si no es un especificador de formato, escribir el carácter en la salida estándar
            write(STDOUT_FILENO, p, 1);
            ++count;
        }
    }

    // Finalizar la lista de argumentos variables
    va_end(args);

    // Retornar la cantidad total de caracteres impresos
    return count;
}

int main() {
    // Ejemplo de uso
    int number = 123;
    char *string = "hello";
    my_printf("Number: %d, String: %s\n", number, string);
    return 0;
