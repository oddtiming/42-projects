#include "ft_printf.h"
#include <limits.h>


//Function to print bits taken from https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
const char *byte_to_binary (int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

int	main(void)
{
	int	return_value;
	t_arg	holder;

	return_value = ft_putnbr_ret(INT_MIN);
	printf("\nreturn value = %d\n", return_value);
	return_value = ft_putstr_ret(NULL);
	printf("\nreturn value = %d\n", return_value);
	return_value = ft_putstr_ret("");
	printf("\nreturn value = %d\n", return_value);
	printf("printf's address of return_value: %p\nMine: ", &return_value);
//	return_value = ft_putaddress_ret((long) &return_value);
//	printf("\nreturn value = %d\n", return_value);
	printf_struct_init(&holder, "test");
	ft_puthex_long((long)&return_value, &holder);
	printf("\nreturn value = %d\n", holder.n_bytes);
	ft_puthex_size_t(LONG_MAX, &holder);
	printf("\nAnd the real printf for LONG_MAX: %p\n", (void *) LONG_MAX);
	ft_puthex_size_t(LONG_MIN, &holder);
	printf("\nAnd the real printf for LONG_MIN: %p\n", (void *) LONG_MIN);
	ft_puthex_size_t(ULONG_MAX, &holder);
	printf("\nAnd the real printf for ULONG_MAX: %p\n", (void *) ULONG_MAX);
	ft_puthex_size_t(-ULONG_MAX, &holder);
	printf("\nAnd the real printf for -ULONG_MAX: %p\n", (void *) -ULONG_MAX);

	printf("size of struct = %zu\n", sizeof(t_arg));

	printf("List of all the flags:\n");
	printf("%#010x %#010x %#010x %#010x %#010x %#010x %#010x \n", FLAG_SPACE, FLAG_HASH, FLAG_PLUS, FLAG_WIDTH, FLAG_PRECISION, FLAG_ZERO, FLAG_MINUS);
/*
	printBits(1, &FLAG_HASH);
	printBits(1, &FLAG_MINUS);
	printBits(1, &FLAG_PLUS);
	printBits(1, &FLAG_PRECISION);
	printBits(1, &FLAG_SPACE);
	printBits(1, &FLAG_WIDTH);
	printBits(1, &FLAG_ZERO);
*/
	printf("FLAG_SPACE: \t%s\n", byte_to_binary(FLAG_SPACE));
	printf("FLAG_HASH: \t%s\n", byte_to_binary(FLAG_HASH));
	printf("FLAG_PLUS: \t%s\n", byte_to_binary(FLAG_PLUS));
	printf("FLAG_WIDTH: \t%s\n", byte_to_binary(FLAG_WIDTH));
	printf("FLAG_PRECISION:\t%s\n", byte_to_binary(FLAG_PRECISION));
	printf("FLAG_ZERO: \t%s\n", byte_to_binary(FLAG_ZERO));
	printf("FLAG_MINUS: \t%s\n", byte_to_binary(FLAG_MINUS));
	sizeof(t_flags)
}