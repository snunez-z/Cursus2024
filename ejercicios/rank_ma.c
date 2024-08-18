/*
 * Implementa esta función: Recibe una cadena de caracteres y tiene que
 * interpretar COMO MUCHO "len" caracteres de la misma y retornar el
 * número entero que representa.
 * La cadena puede tener espacios o tabuladores al principio o al final
 * y puede haber un signo '+' o un signo '-' antes del número.
 * Si hay signo SOLO HABRA UNO: Un '+' o un '-' (o ninguno)
 * También puede haber espacios o tabuladores antes del signo PERO NO
 * DESPUÉS
 *
 * Em caso de error (ver ejemplos), tiene que retornar cero
 *
 * Casos de uso normal:
 * ft_super_atoi("123", 3) tiene que retornar 123
 * ft_super_atoi("123", 2) tiene que retornar 12, porque le estamos
 *                         pidiendo que interprete sólo dos caracteres
 * ft_super_atoi("123", 10) tiene que retornar 123 porque aunque pedimos
 *                          10 caracteres, sólo hay tres. Por eso el
 *                          enunciado dice "COMO MUCHO len caracteres"
 *
 * Casos con espacios:
 * ft_super_atoi(" 123 ", 3) tiene que devolver 12, porque 3 caracteres
 *                           son " 12"
 * ft_super_atoi(" 123 ", 5) tiene que devolver 123
 * ft_super_atoi("     123", 3) tiene que devolver cero porque tres
 *                              caracteres es sólo "   "
 * 
 * Casos con signo:
 * ft_super_atoi("+123", 3) tiene que retornar 12 porque tres caracteres
 *                          son "+12"
 * ft_super_atoi(" -123", 5) tiene que devolver -123
 * ft_super_atoi("  -123  ", 10) tiene que devolver -123
 *
 * Casos de error:
 * ft_super_atoi("Hola", 4) tiene que retornar cero. La 'H' no es un número
 * ft_super_atoi("123a", 4) tiene que retornar cero. La 'a' no es un número
 * ft_super_atoi("  + 123", 6) tiene que retornar cero: Después del signo
 *                             no está el número
 * ft_super_atoi("+-123", 5) tiene que retornar cero: Después del '+' no viene
 *                           el número
 * ft_super_atoi("-+123", 5) tiene que retornar cero: Después del '-' no viene
 *                           el número
 */
int ft_super_atoi(const char *num, size_t len)
{
}

#include <stdio.h>

int main(void)
{
	printf("Esto tiene que pintar 123: %d\n", ft_super_atoi("123", 3));
	printf("Esto tiene que pintar 12: %d\n", ft_super_atoi("123", 2));
	printf("Esto tiene que pintar 123: %d\n", ft_super_atoi("123", 10));
	printf("Esto tiene que pintar 12: %d\n", ft_super_atoi(" 123 ", 3));
	printf("Esto tiene que pintar 123: %d\n", ft_super_atoi(" 123 ", 5));
	printf("Esto tiene que pintar 0: %d\n", ft_super_atoi("     123", 3));
	printf("Esto tiene que pintar 12: %d\n", ft_super_atoi("+123", 3));
	printf("Esto tiene que pintar -123: %d\n", ft_super_atoi(" -123", 5));
	printf("Esto tiene que pintar -123: %d\n", ft_super_atoi("  -123  ", 10));
	printf("Esto tiene que pintar 0: %d\n", ft_super_atoi("Hola", 4));
	printf("Esto tiene que pintar 0: %d\n", ft_super_atoi("123a", 4));
	printf("Esto tiene que pintar 0: %d\n", ft_super_atoi("  + 123", 6));
	printf("Esto tiene que pintar 0: %d\n", ft_super_atoi("+-123", 5));
	printf("Esto tiene que pintar 0: %d\n", ft_super_atoi("-+123", 5));
	return (0);
}

