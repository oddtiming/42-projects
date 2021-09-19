#include <stdio.h>
#include "ft_ultimate_range.c"

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	*range;
	int	min;
	int	max;
	int	result;

	min = 0;
	max = 5;
	result = ft_ultimate_range(&range, min, max);
	printf("Result: %d\n", result);
	return (0);
}
