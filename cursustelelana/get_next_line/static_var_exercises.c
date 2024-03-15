#include <stdio.h>

int	sumar_num ()
{
	static int x;
    x++;
	return (x);
}

int	main(void)
{
	printf("%d\n", sumar_num ());
	printf("%d\n", sumar_num ());
	printf("%d\n", sumar_num());
}

int sumar_num10 ()
{
	static int num = 10;
	num++;
	return (num);
}

int	main(void)
{
	printf("%d\n", sumar_num10());
	printf("%d\n", sumar_num10());
	printf("%d\n", sumar_num10());

}

void calls_counter ()
{
	static int call_numbers = 0;
	call_numbers++;
	printf("Esta funcion ha sido llamada %d veces \n", call_numbers);
}
int	main (void)
{
	
	calls_counter ();
	calls_counter ();
	calls_counter ();
	calls_counter ();
	return (0);
}

int	generate_id()
{
	static int last_id = 0;
	last_id++;
	return (last_id);
}

int main(void)
{
	printf("%d\n", generate_id());
	printf("%d\n", generate_id());
	printf("%d\n", generate_id());
}

int	persistent_add (int value)
{
	static int total = 0;
	total += value;
	return (total);
}

int	main(void)
{
	int value;
	value = printf("Total despues de añadir 5 = %d\n", persistent_add (5));
	value = printf("Total despues de añadir 10 =%d\n", persistent_add (10));
	value = printf("Total despues de añadir 3  =%d\n", persistent_add (3));
}


