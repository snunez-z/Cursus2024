/*Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>*/

#include <unistd.h>
static int	ft_isdigit (char  digit)
{
	if (digit >= '0' && digit <= '9')
		return (1);
	else
		return (0);
}

int 	ft_atoi(const char	*num)
{
	int	value;
	int	i;

    // TODO Yo, por el enunciado, lo que entiendo es que se asume que te van a
    //      pasar un número positivo y, por lo tanto, no hace falta comprobar esto
    //      Pero... lo que te digan tus compis
	if (num[0] == '-')
		i = 1;
	else
		i = 0;
	value = 0;
	while (ft_isdigit(num[i]) != '\0')
	{
		value = (value * 10) + (num[i] - '0');
		i++;
	}
	
	if (num[0] == '-')
		value = value *-1;
	return (value);
}


// Yo, lo siento, voy a asumir que el número es positivo.
// Si hay que soportan negativos.... hablamos, pero el enunciado, para mí,
// es muy claro: Positivos
void ft_putnbr(int num)
{
	char digit;

	// En cada paso (de la recursividad) vamos a poner el último dígito del número.
	// Por ejemplo, del 123, pondremos el 3 (que lo podemos sacar con el % 10)
	// Pero claro... para poder poner el 3, antes hay poner los otros, así es que
	// antes de poner el 3 nos llamamos a nosotros mismos pero pasando un número una
	// cifra más corto. Cómo? Dividiendo entre 10
	// Cuál la condición de fin de recursividad? Que el número que nos pasen sólo tenga
	// una cifra
	if (num > 9)
		// Sólo nos llamamos recursimente si el número es > 9 (es decir, tiene más
		// de una cifra)
		ft_putnbr(num / 10);

	digit = (num % 10) + '0';
	write(1, &digit, 1);
}


/*int	main(int argc, char **argv)
{
	if (argc == 2)
	{


	}
	write (1, "\n", 1);
	return (0);
}
*/

// Una vez tienes hecho el ft_putnbr, la tabla de multiplicar es sencilla:
// Te pasan un número y lo multiplicas x1, luego x2, luego x3, así hasta 9
// Vamos, un bucle del 1 al 10 (no inclusive)
void multiplication(int num)
{
	int multiplicando;

	multiplicando = 1;
	while (multiplicando < 10)
	{
		// Ejemplo de lo que hay que sacar:
		// 2 x 5 = 10
		// 2 es el multiplicando (el que va de 1 a 9)
		// 5 es "num" (lo que nos pasan como parámetro)
		// 10 es el resultado de multiplicar "multiplicando" * "num"
		// El resto de las cosas que hay que poner son siempre las mismas
		// Vamos allá:
		// 1. El multiplicando. Es un número, así es que usamos ft_putnbr
		ft_putnbr(multiplicando);
		// 2. El " x " que va entre los dos números:
		write(1, " x ", 3);
		// 3. El "num"
		ft_putnbr(num);
		// 4. El " = "
		write(1, " = ", 3);
		// 5. El resultado, que es un número
		ft_putnbr(multiplicando * num);
		// 6. Salto de línea
		write(1, "\n", 1);

		// Iteramos
		multiplicando++;
	}
}

#include <stdio.h>
int	main (int argc, char **argv)
{
	int	num;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (-1);
	}

	num = ft_atoi (argv[1]);
	multiplication (num);
	return (0);
}

