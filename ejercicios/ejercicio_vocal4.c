#include <stdio.h>

int	is_vowel (char ch)
{
	char vowels [] ="aeiouAEIOU";
	int	index;

	index = 0;
	while (vowels[index] !='\0')
	{
		if (ch == vowels[index])
			return (1);
		index++;
	}
	return (0);
}

int	is_consonant (char ch)
{
	char	consonants [] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
	int	index;

	index = 0;
	while (consonants[index] != '\0')
	{
		if (ch == consonants [index])
			return (1);
		index++;	
	}
	return (0);
}

int	is_tab_or_space (char ch)
{
	if (ch == '\t' || ch == ' ')
		return (1);
	return (0);	
}

int	main(int argc, char **argv)
{
	
	int	num_vowels;
	int num_consonants;
	int num_tabs_spaces;
	char	*str;
	
	if (argc < 2)
	{
		printf( "usage %s <string>\n", argv[0]);
		return (-1);
	}

	num_vowels = 0;
	num_consonants = 0;
	num_tabs_spaces = 0;
	str = argv[1];
	
	while (*str != '\0' )
	{
		if(is_vowel(*str))
			num_vowels++;
		else if (is_consonant(*str))
			num_consonants++;
		else if (is_tab_or_space (*str))
			num_tabs_spaces++;
		str++;	
	}
	printf ("nº Vocals = %d nº consonants = %d nº tabs = %d \n", num_vowels, num_consonants, num_tabs_spaces);
    if (num_vowels > num_consonants && num_vowels > num_tabs_spaces)
		printf("There are more vowels than consonants and spaces = %d\n", num_vowels);
	else if (num_consonants > num_vowels && num_consonants > num_tabs_spaces)
		printf("There are more consonants than vowels and tabs &spaces = %d\n", num_consonants);
	
	else if (num_tabs_spaces > num_vowels && num_tabs_spaces > num_consonants)
		printf ("There are more tabs&spaces than vowels and consonants = %d\n", num_tabs_spaces);
	return (0);		
}
