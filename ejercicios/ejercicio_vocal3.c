// Haz un programa que retorne numero de vocales, 
//de consonante, el numero de espacios o el numero de tabuladores. 


#include <stdio.h>

int	is_vowel(char ch)
{
	char	vowels[] = "aeiouAEIOU";
	int		index;

	index = 0;
	while (index < 10)
	{
		if (ch == vowels [index])
			return (1);
		index++;
	}
	return (0);
}

int	is_consonant (char ch)
{
	char	consonants [] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
	int		index;

	index = 0;
	while (consonants [index] != '\0')
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

int main (int argc, char**argv)
{
	
	int	num_vowels;
	int	num_consonants;
	int	num_tabs_or_space;
	char	*str;
	
	if (argc < 2)
	{
		printf("usage %s <string>\n", argv [0]);
		return (-1);
	}
	str = argv[1];
    num_vowels = 0;
	num_consonants = 0;
	num_tabs_or_space = 0;
	while (*str !='\0')
	{
		if (is_vowel (*str)) 
			num_vowels++;
		else if (is_consonant (*str))
			num_consonants++;
		else if (is_tab_or_space (*str))
			num_tabs_or_space++;
		str++;	
	}
	printf("Nº Vocals : %d\n Nº Consonants : %d\n Nº Tabs/spaces : %d\n", num_vowels, num_consonants, num_tabs_or_space);
	return (0);
}

