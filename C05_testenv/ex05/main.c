#include <stdio.h>
#include <limits.h>
int	ft_sqrt(int nb);

int	main(void)
{
	int	nb;

	nb = 1;
	printf("nb = %d\nsqrt = %d\n\n", nb, ft_sqrt(nb));
	nb = 81;
	printf("nb = %d\nsqrt = %d\n\n", nb, ft_sqrt(nb));
	nb = 10;
	printf("nb = %d\nsqrt = %d\n\n", nb, ft_sqrt(nb));
	nb = -4;
	printf("nb = %d\nsqrt = %d\n\n", nb, ft_sqrt(nb));
	nb = 1243408644;
	printf("nb = %d\nsqrt = %d\n(should be 35262)\n\n", nb, ft_sqrt(nb));
	printf("Let's check for [0, 10]\n");
	for (int i = 0; i < 11; i++)
	{
		if (ft_sqrt(i))
			printf("nb = %d\nsqrt = %d\n", i, ft_sqrt(i));
	}
	printf("Let's check for INT_MAX - 100000 to INT_MAX\n");
	for (int i = 100000; i > 0; i--)
	{
		nb = INT_MAX;
		if (ft_sqrt(nb - i))
			printf("nb = %d\nsqrt = %d\n", nb - i, ft_sqrt(nb - i));
	}
}
