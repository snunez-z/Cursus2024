#include <stdio.h>

static int ft_strlen(const char *str)
{
    int index;
    index = 0;
    while(str[index] != '\0')
    {
        index++;
    }
    return (index);
}

static int ft_digit_to_int(char digit)
{
    int result;
    result = digit - '0';
    return (result);
}

static int ft_atoi(const char *str)
{
    int index;
    int position_value;
    char digit;
    int value_digit;
    int result;

    result = 0;
    index = ft_strlen(str);
    int position_value = 1;
    while(index >= 0)
    {
        digit = str[index];
        value_digit = ft_digit_to_int(digit);
        result = result + (value_digit * position_value);

        index--;
        position_value = position_value * 10;
    }
    return (result);
}

static int ft_suma(int a, int b)
{
    return (a + b);
}

int main(int argc, char **argv)
{
    int num1;
    int num2;

    // Este programa tiene que sumar todos los números que reciba como parámetro
    // Por ejemplo, si no recibe ninguno, tiene que mostrar (printf) cero
    // Si recibe sólo un parámetro... pues sólo mostrar ese número
    // Si recibe dos, tiene que mostrar la suma de los dos números
    // Si recibe tres, tiene que mostrar la suma de los tres
    // etc
    // No es difícil, pero tampoco es super fácil
    // Tienes una función que suma dos números. Cómo sumas, por ejemplo, tres números?
    // Pues sumando los dos primeros y al resultado, sumarle el tercero
    // Cómo sumo cinco números? Sumo los dos primeros, al resultado le sumo el tercero,
    // al resultado le sumo el cuarto, al resultado le sumo el quinto
}
