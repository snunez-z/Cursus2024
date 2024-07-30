int     search_max(int  *numbers, int num_num)
{
        int     i;
        int     max;
        int     j;

        i = 0;
        j = 0;
        max = numbers[j];
        while (i < num_num)
        {

                if (numbers[i] >= max)
                {
                        max = numbers[i];
                        j = i;
                }
                i++;
        }
        return (j);
}


void sort_int_tab (int *tab, unsigned int size)
{
        int pos_max;
	int	aux;

        if(size <= 1)
            return;         
        pos_max = search_max(tab, size);
        aux = tab[size - 1];
        tab [size - 1] = tab [pos_max];
        tab[pos_max] = aux;
        
        sort_int_tab(tab, size - 1);
}
