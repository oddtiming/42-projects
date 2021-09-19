#include <stdio.h>
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	tabodd[7] = {0, 1, 2, 3, 4, 5, 6};
	int	tabeven[6] = {0, 1, 2, 3, 4, 5};
	int	i;
	int	size;

	size = 7;
	i = -1;
	while (++i < size)
		printf("%d ", tabodd[i]);
	printf("\n");
	ft_rev_int_tab(tabodd, size);
	i = -1;
	while (++i < size)
		printf("%d ", tabodd[i]);
	printf("\n");
	size = 6;
	i = -1;
	while (++i < size)
		printf("%d ", tabeven[i]);
	printf("\n");
	ft_rev_int_tab(tabeven, size);
	i = -1;
	while (++i < size)
		printf("%d ", tabeven[i]);
	printf("\n");
	return (0);
}
