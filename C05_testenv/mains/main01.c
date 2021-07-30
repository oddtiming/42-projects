#include <stdio.h>
int	ft_recursive_factorial(int nb);

int	main(void)
{
	int	nb;

	nb = 6;
	printf("For nb = %d\nFactorial = %d\n(should be 720)\n", nb, ft_recursive_factorial(nb));
	nb = -5;
	printf("\nFor nb = %d\nFactorial = %d\n(should return 0)\n", nb, ft_recursive_factorial(nb));
	nb = 12;
	printf("\nFor nb = %d\nFactorial = %d\n(should return 479001600)\n\n", nb, ft_recursive_factorial(nb));
}
