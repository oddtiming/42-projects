#include <limits.h>
#include <stdio.h>
#include <unistd.h>
void	ft_putnbr(int nb);

int	main(void)
{
	int	nb;

	nb = 10000;
	printf("Fed number is : %d\n", nb);
	ft_putnbr(nb);
	nb = -10000;
	printf("\nFed number is : %d\n", nb);
	ft_putnbr(nb);
	nb = INT_MAX;
	printf("\nFed number is : %d\n", nb);
	ft_putnbr(nb);
	nb = INT_MIN;
	printf("\nFed number is : %d\n", nb);
	ft_putnbr(nb);
	nb = INT_MIN / 10;
	printf("\nFed number is : %d\n", nb);
	ft_putnbr(nb);
	printf("\n");
	return (0);
}
