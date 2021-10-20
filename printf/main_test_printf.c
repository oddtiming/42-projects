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
}