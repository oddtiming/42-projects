#include <stdlib.h>
#include <stdio.h>
#include "ft_range.c"

void	print_range (int min, int max);

int	main (void)
{
	int	min;
	int	max;
	
	min = 3;
	max = 7;
	print_range (min, max);
	
	min = -6;
	max = 3;
	print_range (min, max);
	
	printf ("Should print nothing\n");
	min = 0;
	max = 0;
	print_range (min, max);

	printf ("Should print nothing\n");
	min = 1;
	max = -6;
	print_range (min, max);

}

void	print_range (int min, int max)
{
	int	len;
	int	i;
	
	len = max - min;
	i = 0;
	printf ("Min = %d | Max = %d\n", min, max);
	while (i < max - min)
	{
	printf ("%d  ", ft_range (min, max)[i]);
		i++;
	}
	printf ("\n\n");
}

