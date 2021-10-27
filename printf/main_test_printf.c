#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>


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
	t_arg	arg;
	char	*format1 = "%#- +010.9s";

	return_value = ft_putnbr_ret(INT_MIN);
	printf("\nreturn value = %d\n", return_value);
	return_value = ft_putstr_ret(NULL);
	printf("\nreturn value = %d\n", return_value);
	return_value = ft_putstr_ret("");
	printf("\nreturn value = %d\n", return_value);
	printf("printf's address of return_value: %p\nMine: ", &return_value);
//	return_value = ft_putaddress_ret((long) &return_value);
//	printf("\nreturn value = %d\n", return_value);
	printf_struct_init(&arg, "test");
	ft_puthex_size_t((long)&return_value, &arg);
	printf("\nreturn value = %d\n", arg.n_bytes);
	ft_puthex_size_t(LONG_MAX, &arg);
	printf("\nAnd the real printf for LONG_MAX: %p\n", (void *) LONG_MAX);
	ft_puthex_size_t(LONG_MIN, &arg);
	printf("\nAnd the real printf for LONG_MIN: %p\n", (void *) LONG_MIN);
	ft_puthex_size_t(ULONG_MAX, &arg);
	printf("\nAnd the real printf for ULONG_MAX: %p\n", (void *) ULONG_MAX);
	ft_puthex_size_t(-ULONG_MAX, &arg);
	printf("\nAnd the real printf for -ULONG_MAX: %p\n", (void *) -ULONG_MAX);

	printf("size of struct = %zu\n", sizeof(t_arg));

	printf("List of all the flags:\n");
	printf("%#010x %#010x %#010x %#010x %#010x %#010x %#010x \n", FLAG_SPACE, FLAG_HASH, FLAG_PLUS, FLAG_WIDTH, FLAG_PREC, FLAG_ZERO, FLAG_MINUS);

	printf("FLAG_SPACE: \t%s\n", byte_to_binary(FLAG_SPACE));
	printf("FLAG_HASH: \t%s\n", byte_to_binary(FLAG_HASH));
	printf("FLAG_PLUS: \t%s\n", byte_to_binary(FLAG_PLUS));
	printf("FLAG_WIDTH: \t%s\n", byte_to_binary(FLAG_WIDTH));
	printf("FLAG_PREC:\t%s\n", byte_to_binary(FLAG_PREC));
	printf("FLAG_ZERO: \t%s\n", byte_to_binary(FLAG_ZERO));
	printf("FLAG_MINUS: \t%s\n", byte_to_binary(FLAG_MINUS));
	free (arg.format);

	printf("Let's test arg_parse_dev for format = \"%s\"\n", format1);
	printf_struct_init(&arg, format1);
	arg_parse_dev(&arg);
	printf("arg->flags: \t%s\n", byte_to_binary(arg.flags));
	printf("arg->flags in int value: %d\n", arg.flags);
	printf("arg->width = %d\n", arg.width);
	printf("arg->precision = %d\n", arg.precision);
	printf("arg->var_type = %c\n", arg.var_type);

	// printf("\n--------TESTS for octal and hexa--------\n");
	// return_value = printf("For printf: %d\n", 00032);
	// printf("return value = %d\n", return_value);
	// return_value = ft_printf("for ft_printf: %d\n", 00032);
	// printf("return value = %d\n", return_value);
	// return_value = printf("For printf: %d\n", 0xabc4);
	// printf("return value = %d\n", return_value);
	// return_value = ft_printf("for ft_printf: %d\n", 0xabc4);
	// printf("return value = %d\n", return_value);
}