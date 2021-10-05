#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	arg_ptr;
//	char	*output_string;
	int		i;

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
				ft_putnbr_fd( (unsigned int) va_arg(arg_ptr, int), 1);
			else if (format[i] == 's')
				ft_putstr_fd(va_arg(arg_ptr, char *), 1);
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

int	main()
{
	int		i1, i2, i3;
	char	*str1 = "This is the first string";
	char	*str2 = " And I shall want to add this";
	char	*format = " %d, %i, %u, %x, %s, %c, %X, %p, %%p of &i1: %p, \n";
	int		return_value;
	
	i1 = 48;
	i2 = 2;
	i3 = 49;
	printf("format = %s\n", format);
	return_value = ft_printf(format, i1, i2, i3, str1, str2, 'c', str1, i1);
	printf("The return value is '%d'\n", return_value);
	return_value = printf(format, i1, i2, i3, str1, str2, 'c', str1, i1);
	printf("The return value is '%d'\n", return_value);
	return (0);
}
