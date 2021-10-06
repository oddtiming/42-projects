#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	arg_ptr;
	int		i, temp_i;
	char *s;

	i = 0;
	va_start(arg_ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'i' || format[i] == 'd')
				ft_putnbr_fd(va_arg(arg_ptr, int), 1);
			else if (format[i] == 'u')
			{
				temp_i = (unsigned int)va_arg(arg_ptr, int);
				printf("in ft_printf 'u', temp_i = '%d'\n", temp_i);
				ft_putnbr_fd(temp_i, 1);
			}
			else if (format[i] == 's')
			{
				s = va_arg(arg_ptr, char *);
				ft_putstr_fd(s, 1);
			}	
			else if (format[i] == 'x' || format[i] == 'X')
				ft_writehex(va_arg(arg_ptr, int), format[i]);
			else if (format[i] == 'c')
				ft_putchar_fd(va_arg(arg_ptr, int), 1);
			else if (format[i] == 'p')
			{
				ft_putstr_fd("0x", 1);
				ft_writehex_long(va_arg(arg_ptr, long));
			}
			else if (format[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
			write (1, &format[i], 1);
		i++;
	}
	va_end(arg_ptr);
	return (0);
}

int	main(void)
{
	int		i1, i2, i3;
	char	*str1 = "This is the first string";
	char	*str2 = " And I shall want to add this";
	char	*format = " %d, %i, %u, %%x of str1: %x, %s, %s, %c, %%p of str1: %p, %%X of i1: %X\n";
	int		return_value;

	i1 = -48;
	i2 = 2;
	i3 = 49;
	printf("format = %s\n", format);
	return_value = ft_printf(format, i1, i1, i1, str1, str1, str2, 'c', str1, i1);
	printf("The return value is '%d'\n", return_value);
	return_value = printf(format, i1, i1, i1, str1, str1, str2, 'c', str1, i1);
	printf("The return value is '%d'\n", return_value);
	return (0);
}
