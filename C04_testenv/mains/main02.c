#include <stdio.h>
#include <limits.h>
void	ft_putnbr(int nb);

int	main(void)
{
	int nb1 = 0;
	int nb2 = 1000;
	int nb3 = -1234;
	int nb4 = INT_MIN;

	printf("for nb = %d, your fct prints: \n", nb1);
	ft_putnbr(nb1);
	printf("\n\nfor nb = %d, your fct prints: \n", nb2);
	ft_putnbr(nb2);
	printf("\n\nfor nb = %d, your fct prints: \n", nb3);
	ft_putnbr(nb3);
	printf("\n\nfor nb = %d, your fct prints: \n", nb4);
	ft_putnbr(nb4);
	printf("\n");
}
