#include "ft_printf.h"

int	ft_printf_bonus(const char *format, ...)
{
	va_list	ap;
	t_arg	*pf_struct;

	va_start(ap, format);
	//Need to parse the format string
	//Store the appropriate flags in the appropriate locations


	va_end(ap);
	//The struct holds all the relevant information
	return (pf_struct->n_bytes);
}

int main (void)
{
	int		i1, i2, i3;
	char	*str1 = "This is the first string";
	char	*str2 = " And I shall want to add this";
	char	*format = " 1 = %%d : %d, 2 = %%i: %i, %u, %%x of str1: %x, %s, %s, %c, %%p of str1: %p, %%X of i1: %X\n";
	int		return_value;

	i1 = -48;
	i2 = 2;
	i3 = 49;
	printf("format = %s\n", format);
	return_value = ft_printf_bonus(format, i1, i1, i1, str1, str1, str2, 'c', str1, i1);
	printf("The return value is '%d'\n", return_value);
	return_value = printf(format, i1, i1, i1, str1, str1, str2, 'c', str1, i1);
	printf("The return value is '%d'\n", return_value);
	return (0);
}