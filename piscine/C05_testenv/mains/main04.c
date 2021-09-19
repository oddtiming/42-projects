#include <stdio.h>
int	ft_fibonacci(int index);

int	main(void)
{
	int	index;

	index = 9;
	printf("The %dth element of the Fibonacci sequence is %d\n(should be 34)\n\n", index, ft_fibonacci(index));
	index = 0;
	printf("The %dth element of the Fibonacci sequence is %d\n(should be 0)\n\n", index, ft_fibonacci(index));
	index = -1;
	printf("The %dth element of the Fibonacci sequence is impossible, therefore, your function should return  %d\n", index, ft_fibonacci(index));
}
