#include <stdio.h>
int	ft_iterative_factorial(int nb);

int	main(void)
{
	int	nb;

	nb = 5;
	printf("For nb = %d\nFactorial = %d\n(should be 120)\n", nb, ft_iterative_factorial(nb));
	nb = -5;
	printf("\nFor nb = %d\nFactorial = %d\n(should return 0)\n", nb, ft_iterative_factorial(nb));
	nb = 12;
	printf("\nFor nb = %d\nFactorial = %d\n(should return 479001600)\n\n", nb, ft_iterative_factorial(nb));
}
