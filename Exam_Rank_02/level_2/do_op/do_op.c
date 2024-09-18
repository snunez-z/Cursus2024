/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 07:58:31 by snunez-z          #+#    #+#             */
/*   Updated: 2024/09/18 16:26:03 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char	**argv)
{
	int	num1;
	int	num2;

	if (argc == 4)
	{
		num1 = atoi (argv[1]);
		num2 = atoi (argv[3]);
		if (argv[2][0] == '+')
			printf ("%d", num1 + num2);
		else if (argv[2][0] == '-')
			printf("%d", num1 - num2);	
		else if (argv[2][0] == '*')
			printf ("%d", num1 * num2);
		else if (argv[2][0] == '%')
			printf("%d", num1 % num2);
		else if (argv[2][0] == '/')
			printf("%d", num1 / num2);
	}
	printf("\n");
	return (0);
}

