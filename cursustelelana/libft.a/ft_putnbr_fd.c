/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:21:19 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/08 13:02:57 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

static void	ft_putnbr_without_sign(unsigned int n, int fd)
{
    char    digit;

    // El fin de la recursividad lo marca cuando, a base de dividir "n" entre 10,
    // llegamos al cero
    if (n == 0)
    {
        return;
    }

    // Primero tenemos que poner los dígitos que hay más a la izquierda, así es,
    // antes de poner este dígito, nos llamamos a nosotros mismos, pero dividiendo
    // entre 10 para irnos acercando a la cifra más a la izquierda.
    // Por ejemplo: 123
    // La primera cifra que tenemos que escribir es el 1, pero si ahora hacemos
    // 123 % 10 nos va a dar 3 (la cifra más a la derecha), así es que nos llamamos
    // a nosotros mismos pasando 123 / 10, que es 12 y ya estaremos más cerca de
    // poder poner el 1
    ft_putnbr_without_sign(n / 10, fd);

    // Una vez se han escrito todos los dígitos a la izquierda de este, ya podemos
    // poner este
    digit = (n % 10) + '0';
    write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
    unsigned int    unsigned_n;

    // Excepción: Si el número que nos pasan es el cero, no tenemos que andarnos con divisiones
    // ni restos ni nada. Escribimos un cero y a correr
    if (n == 0)
    {
        write(fd, "0", 1);
        return;
    }

    // Si el número es negativo, lo primero que tenemos que poner es el signo "-"
    if (n < 0)
    {
        write(fd, "-", 1);
        // Una vez hemos puesto el "-" ya podemos trabajar como si el número fuese
        // positivo (es más cómodo)
        unsigned_n = (n * -1);
    }
    else
        unsigned_n = n;


    ft_putnbr_without_sign(unsigned_n, fd);
}

int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;
	ft_putnbr_fd(0, stdout_fd);
	printf("\n");
	ft_putnbr_fd(555, stdout_fd);
	printf("\n");
	ft_putnbr_fd(-555, stdout_fd);
	printf("\n");
	ft_putnbr_fd(-1247000, stdout_fd);
	printf("\n");
	ft_putnbr_fd(0, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(35, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(2147483647, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(-2147483648, stdout_fd);
	printf("\n");
	return (0);
}

