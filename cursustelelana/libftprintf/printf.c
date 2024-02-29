#include <stdio.h>
#include <stdarg.h>

// retorna un int para poder controlar los fallos, si retorna un int positivo es que tuvo exito.
int	ft_printf(char const *, ...);

va_start
va_arg( args,  char * )

while (*str != '\0' &&  *str != % )
	str++;
if (*str == c)
{
	ft_putchar_fd(*str);
if else (*str == s)
	putstr_fd (string, STDOUT_FILENO);

}


	
int	main (void);

int	result;

result = 1;

printf("El resultado es = %d", result);
result (0);i


/ Definición de nuestra función personalizada
void my_printf(const char *format, ...) {
    // Inicializar el puntero de argumentos variables
    va_list args;
    va_start(args, format);

    // Variable para contar los caracteres impresos
    int count = 0;

    // Iterar a través del formato de cadena
    for (const char *p = format; *p != '\0'; ++p) {
        // Si encontramos un especificador de formato
        if (*p == '%') {
            // Avanzar al siguiente carácter
            ++p;

            // Verificar el tipo de formato
            switch (*p) {
                case 'd': {
                    // Si es un entero, obtenemos el valor del argumento
                    int value = va_arg(args, int);
                    // Convertir el entero a una cadena de caracteres
                    char buffer[20]; // Suponemos que el entero no excede los 20 dígitos
                    int length = snprintf(buffer, sizeof(buffer), "%d", value);
                    // Escribir la cadena de caracteres en la salida estándar
                    write(STDOUT_FILENO, buffer, length);
                    count += length;
                    break;
                }
                case 's': {
                    // Si es una cadena de caracteres, obtenemos el valor del argumento
                    char *str = va_arg(args, char*);
                    // Escribir la cadena de caracteres en la salida estándar
                    int length = 0;
                    while (str[length] != '\0') {
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
