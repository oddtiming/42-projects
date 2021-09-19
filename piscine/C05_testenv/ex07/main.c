#include <stdio.h>
int	ft_find_next_prime(int nb);
int	next_prime(int nb);
int	ft_is_prime(int nb);

int	main(void)
{
	int nb;

	nb = 1;
	printf("For nb = %d, the next prime is %d\n(should be %d)\n\n", nb, ft_find_next_prime(nb), next_prime(nb));
	nb = 13;
	printf("For nb = %d, the next prime is %d\n(should be %d)\n\n", nb, ft_find_next_prime(nb), next_prime(nb));
	nb = 100;
	printf("For nb = %d, the next prime is %d\n(should be %d)\n\n", nb, ft_find_next_prime(nb), next_prime(nb));
	nb = -10;
	printf("For nb = %d, the next prime is %d\n(should be %d)\n\n", nb, ft_find_next_prime(nb), next_prime(nb));
	nb = 2147483630;
	printf("For nb = %d, the next prime is %d\n(should be %d)\n", nb, ft_find_next_prime(nb), next_prime(nb));
}

int	next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
