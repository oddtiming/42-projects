#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	buffer;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		buffer = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = buffer;
		i++;
	}
}
