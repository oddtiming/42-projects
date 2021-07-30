#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void intPrint(int i)
{
	if (i >= 10)
		intPrint(i / 10);
	ft_putchar(i % 10 + '0');
}

int	main(void)
{
	int test1 = 42;
	printf("Fed number is %d\n", test1);
	intPrint(test1);
	ft_putchar('\n');
	int test2 = 1000;
	printf("Fed number is %d\n", test2);
	intPrint(test2);
	ft_putchar('\n');
	printf("9 %% 10 is %d\n", (9 % 10));
}
