#include <stdlib.h>
#include <stdio.h>


int	main(void)
{
	size_t count = 3;
	size_t size = sizeof(int);
	char *test_mem = ft_calloc(count, size);

	for (int i = 0; i < size * count; i++)
	{
		printf("%c, ", test_mem(i));
	}

}
