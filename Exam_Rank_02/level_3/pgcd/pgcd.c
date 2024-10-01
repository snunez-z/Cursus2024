/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:58:51 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:58:54 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int a;
	int b;
	int cd;

	if (argc < 3 || atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0)
	{
		printf("\n");
		return (-1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	if (a < b)
		cd = a;
	else
		cd = b;
	while (cd >= 1)
	{
		if ((a % cd) == 0 && (b % cd) == 0)
		{
			printf("%d\n", cd);
			return (0);
		}
		cd--;
	}
	return (0);
}
