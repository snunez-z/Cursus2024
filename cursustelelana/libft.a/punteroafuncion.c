/* ejemplo de punto a funciones. 
 * una funcion ft_operacion que sirve para realizar una operacion etre dos numeros de cualquier tipo que previamente este creada. retorna un int y recibe dos ints, el puntero a la funcion elegida que a su vez recibe lso dos int que van a operar en esa funcion).*/

#include <stdio.h>

int	ft_suma(int num1, int num2)
{
	int	suma;
	suma = num1 + num2;
	return (suma);
}

int	ft_resta(int num1, int num2)
{	
	int	resta;
	resta = num1 - num2;
	return (resta);
}

int ft_operacion(int  num1, int num2, int (*op)(int, int))
{
	int result;
	result = (*op)(num1, num2);
	return result;
}
	
int ft_min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	printf("%d\n", ft_operacion(5, 3, ft_suma));
	printf("%d\n", ft_operacion(5, 3, ft_resta));
	printf("%d\n", ft_operacion(5, 3, ft_min));
}
