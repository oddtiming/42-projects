#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;
	int	*ptr_a;
	int	*ptr_b;

	a = 0;
	b = 1;
	ptr_a = &a;
	ptr_b = &b;
	printf("a = %d and b = %d\n", a, b);
	ft_swap(ptr_a, ptr_b);
	printf("But now a = %d and b = %d\nTADAAAA!\n", a, b);
}
