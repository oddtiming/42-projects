#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;
	int	*p_div;
	int	*p_mod;

	a = 31;
	b = 16;
	p_div = &div;
	p_mod = &mod;
	printf("a = %d, b = %d\n", a, b);
	ft_div_mod(a, b, p_div, p_mod);
	printf("a / b = %d, and a %% b = %d\n", div, mod);
	return (0);
}
