#include <stdio.h>

static int ft_strlen(const char *str)
{
    // Venga, practica este, como repaso
}

static int ft_digit_to_int(char digit)
{
    // Implementa esta función que retorna el valor del dígito
    // Por ejemplo: para '0' tiene que retornar 0 y para '9' tiene que
    // retornar 9
}

static int ft_atoi(const char *str)
{
    int index;
    int position_value;
    char digit;
    int value_digit;
    int result;

    // Rellena los huecos en esta función para poder convertir una cadena de
    // caracteres en número entero
    // La lógica es: La posición de más a la derecha vale 1, la anterior 10,
    // la anterior 100, la anterior 1000 y así sucesivamente
    // Ejemplo: 12345
    // La posición de más a la derecha vale 1 => 1 * 5 = 5
    // La anterior vale 10 => 10 * 4 = 40
    // La anterior vale 100 => 100 * 3 = 300
    // La anterior vale 1000 => 1000 * 2 = 2000
    // La anterior vale 10000 => 10000 * 1 = 10000
    // Es decir, recorremos la cadena de derecha a izquierda y la parte de
    // "incremento" del bucle son dos cosas:
    // - Pasar a la posición anterior del bucle
    // - El valor de esa posición es el valor de la posición anterior * 10
    result = ...;
    index = ft_strlen(str);
    int position_value = 1;
    while(...)
    {
        digit = str[...];
        value_digit = ft_digit_to_int(digit);
        result = result + ...;

        index--;
        position_value = position_value * 10;
    }
    return (result);
}

static int ft_suma(int a, int b)
{
    // Implementa esta función. Sencilla :)
}

int main(int argc, char **argv)
{
    int num1;
    int num2;

    // Este programa tiene que sumar dos números, así es que si
    // no recibe como mínimo dos parámetros (además del nombre 
    // del programa) tiene que sacar un mensaje de error y retornar

    // Vale, tenemos dos parámetros:
    // Conviértelos a int, súmalos y haz printf del resultado
}
