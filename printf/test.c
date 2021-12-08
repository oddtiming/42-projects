#include <stdio.h>

int	main()
{
	// int		flags_index[6];// = {FLAG_MINUS, FLAG_ZERO, FLAG_PREC, FLAG_HASH, FLAG_SPACE, FLAG_PLUS};
	// int		num_value;
	// int		filler;

	// num_value = 0;
	// filler = 1;
	// while (num_value < 6)
	// {
	// 	flags_index[num_value] = 1 << num_value;
	// 	num_value++;
	// }
	// num_value = 0;
	// while (num_value < 6)
	// {
	// 	printf("flags_index[%d] = %#x\n", num_value, flags_index[num_value]);
	// 	num_value++;
	// }
	size_t test_size;
	double long long_size;

	printf("size of test = %lu\n", sizeof(test_size));
	printf("size of long long= %lu\n", sizeof(long_size));

}