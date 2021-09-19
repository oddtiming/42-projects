#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
unsigned int	ft_size(int min, int max);
int	*ft_range(int min, int max);

int	main(void)
{
	int	min;
	int	max;
	int	*tab;
	unsigned int	size;
	unsigned int	i;

	min = -5;
	max = 10;
	printf("For min = %d and max = %d, the array is :\n", min, max);
	size = ft_size(min, max);
	tab = (int *)malloc((size)*sizeof(int));
	tab = ft_range(min, max);
	i = 0;
	printf("[%d ", tab[i]);
	while (++i < size - 1)
		printf("%d ", tab[i]);
	printf("%d]\n\n", tab[i]);
	free (tab);
	min = INT_MIN;
	max = INT_MIN + 5;
	printf("For min = %d and max = %d, the array is :\n", min, max);
	size = ft_size(min, max);
	tab = (int *)malloc((size)*sizeof(int));
	tab = ft_range(min, max);
	i = 0;
	printf("[%d ", tab[i]);
	while (++i < size - 1)
		printf("%d ", tab[i]);
	printf("%d]\n\n", tab[i]);
	free (tab);
	min = 0;
	max = 1;
	printf("For min = %d and max = %d, the array is :\n", min, max);
	size = ft_size(min, max);
	tab = (int *)malloc((size)*sizeof(int));
	tab = ft_range(min, max);
	i = 0;
	if (size == 1)
		printf("[%d]\n\n", tab[i]);
	else
		printf("[%d ", tab[i]);
	while (++i < size - 1)
		printf("%d ", tab[i]);
	if (i > 1)
		printf("%d]\n\n", tab[i]);
	free (tab);
	min = 0;
	max = 0;
	printf("For min = %d and max = %d, the array is :\n", min, max);
	size = ft_size(min, max);
	tab = (int *)malloc((size)*sizeof(int));
	tab = ft_range(min, max);
	if (tab == NULL)
		printf("NULL\n");
	else 
		printf("%d\n", *tab);
	free (tab);
}
