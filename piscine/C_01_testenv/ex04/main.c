#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;
	int	*p_a;
	int	*p_b;

	a = 92;
	b = 10;
	p_a = &a;
	p_b = &b;
	printf("a = %d, b = %d\n", a, b);
	ft_ultimate_div_mod(p_a, p_b);
	printf("a / b = %d and a '%%'  b = %d\n", a, b);
	return (0);
}
