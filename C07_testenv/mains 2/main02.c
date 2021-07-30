#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
unsigned int	ft_size(int min, int max);
int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	min;
	int	max;
	int	size;
	int	*tab;
	int **range;
	int	i;

	tab = 0;
	range = &tab;

	min = 0;
	max = 5;
	size = ft_size(min, max);
	printf("For min = %d and max = %d, the size of int **range is :\n", min, max);
	printf("%d\n", ft_ultimate_range(range, min, max));
	for (int i = 0; i < size; i++)
		printf("%d ", (*range)[i]);
	printf("\n\n");
	free (*range);
	min = 5;
	max = 1;
	size = ft_size(min, max);
	printf("For min = %d and max = %d, the size of int **range is :\n", min, max);
	printf("%d\n", ft_ultimate_range(range, min, max));
	for (int i = 0; i < size; i++)
		printf("%d ", (*range)[i]);
	printf("\n");
	min = 0;
	max = 1;
	size = ft_size(min, max);
	printf("For min = %d and max = %d, the size of int **range is :\n", min, max);
	printf("%d\n", ft_ultimate_range(range, min, max));
	for (int i = 0; i < size; i++)
		printf("%d ", (*range)[i]);
	printf("\n\n");
	min = 11;
	max = 15;
	size = ft_size(min, max);
	printf("For min = %d and max = %d, the size of int **range is :\n", min, max);
	printf("%d\n", ft_ultimate_range(range, min, max));
	for (int i = 0; i < size; i++)
		printf("%d ", (*range)[i]);
	printf("\n");
	free (*range);
}
