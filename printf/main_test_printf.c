#include "ft_printf.h"
#include <limits.h>

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
	printf("\nAnd the real printf for LONG_MAX: %p\n", LONG_MAX);
	ft_puthex_size_t(LONG_MIN, &holder);
	printf("\nAnd the real printf for LONG_MIN: %p\n", LONG_MIN);
	ft_puthex_size_t(ULONG_MAX, &holder);
	printf("\nAnd the real printf for ULONG_MAX: %p\n", ULONG_MAX);
	ft_puthex_size_t(-ULONG_MAX, &holder);
	printf("\nAnd the real printf for -ULONG_MAX: %p\n", -ULONG_MAX);
}