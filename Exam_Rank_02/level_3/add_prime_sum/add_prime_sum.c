/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:54:21 by snunez-z          #+#    #+#             */
/*   Updated: 2024/09/10 09:31:24 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_prime (int num)
{
	int	i;

	i = 2;
	while (i < num)
	{
		if ((num % i) == 0)
		   return (0);
		i++;	
	}
	return (1);
}

int	ft_atoi (char	*num)
{
	int value;
	
	value = 0;
	while (*num != '\0')
	{
		value = (value * 10) + (*num - '0');
		num ++;
	}
	return (value);	
}

void	put_nbr(int num)
{
	 char	digit;

	if (num >= 10)
		put_nbr (num / 10);
	digit = (num % 10) + '0';
	write (1, &digit, 1);
}

int	main (int argc, char	**argv)
{
	int num;
	int	add;

	if (argc < 2 || argv[1][0] == '-')
	{
		write (1, "0\n", 2);
		return (0);
	}
	
	num = ft_atoi (argv[1]);
		add = 0;
		while (num > 1)
		{
			if(is_prime (num) == 1) 
				add = add + num; 
			num --;
		}
	put_nbr(add);
	write (1, "\n", 1);
	return (0);
}

