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

static int ft_acumular(int a)
{
    // Ups!!!! Esta función sólo recibe un parámetro (un número) y tiene que retornar el acumulado
    // de todas las veces que se haya llamado. Es decir, si la primera vez llamo con a=10, tiene
    // que retornar 10 (porque es la primera vez que se llama).
    // Si la segunda vez llamamos con a=5, tiene que retornar 15 (10 de antes y 5 de ahora). Si la
    // tercera vez llamamos con a=4, tiene que retornar 19 (10 + 5 + 4)
    // Es decir... tiene que retornar el acumulado hasta ese momento. Te suena??? "static"
}

int main(int argc, char **argv)
{
    int acumulado;
    int index;
    int num;

    acumulado = 0;
    index = 1;
    while (index < argc)
    {
        num = ft_itoa(argv[index]);
        acumulado = ft_acumular(num);
        index++;
    }
    printf("El total es: %d\n", acumulado);
    return (0);
}
