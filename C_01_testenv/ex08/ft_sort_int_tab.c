#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	buffer;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				buffer = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = buffer;
			}
			j++;
		}
		i++;
	}
}
