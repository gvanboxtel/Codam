#include <stdio.h>

void    ft_sort_int_tab(int *tab, int size)
{
    int s = size -1;
    int temp[size];
    int i = 0;
    
    while (i <= s)
    {
        temp[i] = tab[i];
        
        //printf("%d ", temp[i]);
        i++;
    }

    i = 0;
      
    while (tab[i] > tab[s-i])
    {
		while(tab[i] >= tab[i+1] && tab[i] != tab[s])
		{
			if(tab[i] < tab[i+1])
			{
				tab[i] = tab[i];
			}
			
			else
			{
				tab[i+1] = temp[i];
				tab[i] = temp[i+1];
			}
			
			//printf("%d ", tab[i]);
			i++;
		}
		if (tab[i] = tab[s])
			{
				tab[i] = temp[s];
				tab[s] = temp[i];
			}
		i++;
		i = 0;
		

        
        

    }
	for (i=0;i<=s;i++)
	{
		printf("\ntab array: %d", tab[i]);
	}

}

int    main(void)
{
    int myNumbers[] = {50, 124, 3123, 2};
    int *ptr = myNumbers;
    int size;

    size = 4;
    ft_sort_int_tab(ptr, size);
    return (0);
}