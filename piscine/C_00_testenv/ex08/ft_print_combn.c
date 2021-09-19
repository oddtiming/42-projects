#include <unistd.h>
#include <stdio.h>

void	printchar(char c);

void	ft_print_combn(int n)
{
	int	dig[9];
	int	i;

	i = -1;
	while (++i < n)
	{
		dig[i] = i;
		printchar(dig[i] + '0');
	}
	i -= 1;
	printf("\nindex is at %d", i);
	while (dig[0] != 10 - n)
	{
		while ((dig[i] != 10 - n + i) && dig[i-1] < dig[i])
		{
			dig[i]++;
		}
		dig[i] = dig[i-1] + 1;
		i--;
	}
	i = -1;
	while (++i < n)
		printchar(dig[i] + '0');
	i -= 1;	
}

void	printchar(char c)
{
	write(1, &c, sizeof(c));
}

int	main(void)
{
	int	a;

	a = 3;
	ft_print_combn(a);
	printf("\nFed number is : %d\n", a);
	return (0);
}
