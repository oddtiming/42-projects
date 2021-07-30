#include <stdio.h>
#include <limits.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	tab[7] = {INT_MAX, 3, 2, 0, -1, -3, INT_MIN};
	int	i;
	int	size;

	size = 7;
	i = -1;
	while (++i < size)
		printf("%d ", tab[i]);
	printf("\n");
	ft_sort_int_tab(tab, size);
	i = -1;
	while (++i < size)
		printf("%d ", tab[i]);
	printf("\n");
	return (0);
}
