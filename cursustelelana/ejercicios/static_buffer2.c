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
    index = ft_strlen(str) -1;
    position_value = 1;
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
    int num3;
    int result;
    int index;

    if (argc == 1)
        printf("0");
    if (argc == 2)
    {
        num1 = ft_atoi(argv[1]);
        printf ("%d\n", num1);
    }
    if (argc == 3)
    {
        num1 = ft_atoi(argv[1]);
        num2 = ft_atoi(argv[2]);
        result = ft_suma (num1, num2);
        printf("%d\n", result);
    }

    if (argc >= 4)
    {
        num1 = ft_atoi(argv[1]);
        num2 = ft_atoi(argv[2]);
        result = ft_suma (num1, num2);
        index = 3;
        while ( index < argc)
        {
            result = ft_suma (result, ft_atoi(argv[index]));
            index++;
        }
            printf("%d\n", result);
    }
    


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
