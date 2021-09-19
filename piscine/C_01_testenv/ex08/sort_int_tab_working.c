#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	buffer;
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab [i+1])
		{
			buffer = tab[i];
			printf("Switching %d and %d\n", tab[i], tab[i+1]);
			tab[i] = tab[i+1];
			tab[i+1] = buffer;
			i = -1;
		}
		i++;
	}
}
