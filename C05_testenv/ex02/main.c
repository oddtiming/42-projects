#include <stdio.h>
#include <limits.h>
int	ft_iterative_power(int nb, int power);

int	main(void)
{
	int	nb;
	int	power;

	nb = 2;
	power = 8;
	printf("For nb = %d and power = %d\nnb^power = %d\n\n", nb, power, ft_iterative_power(nb, power));
	nb = 0;
	power = 0;
	printf("For nb = %d and power = %d\nnb^power = %d\n\n", nb, power, ft_iterative_power(nb, power));
	nb = -2;
	power = 5;
	printf("For nb = %d and power = %d\nnb^power = %d\n\n", nb, power, ft_iterative_power(nb, power));
	nb = -10;
	power = 0;
	printf("For nb = %d and power = %d\nnb^power = %d\n\n", nb, power, ft_iterative_power(nb, power));
	nb = -10;
	power = -2;
	printf("For nb = %d and power = %d\nnb^power = %d\n\n", nb, power, ft_iterative_power(nb, power));
	nb = -102;
	power = 1;
	printf("For nb = %d and power = %d\nnb^power = %d\n", nb, power, ft_iterative_power(nb, power));
}
