#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int d = 1000;
	int firstDig;
	int remainder;
	int	divider;

	divider = 1;
	while (d / (10 * divider) != 0)
	{
		divider = 10 * divider;
	}
	printf("initial number: %d\n", d);
	firstDig = d / divider;
	printf("divider: %d\n", divider);
	printf("first digit is: %d\n", firstDig);
	remainder = d % 10000;
	printf("remainder is: %d\n", remainder);
	if (remainder / (divider / 10))
		printf("remainder is: %d\n", remainder);
	return (0);
}
