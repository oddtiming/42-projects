#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	t_arg	arg;

	va_start(ap, format);
	printf_struct_init(&arg, format);
	while (format[arg.index])
	{
		//Parsing the conversion
		if (format[arg.index] == '%')
		{
			arg_parse(&arg, ap);
			printf_struct_reset(&arg);
		}
		//Printing the format string char by char
		else
		{
			write(1, &format[arg.index], 1);
			arg.index += 1;
			arg.n_bytes += 1;
		}
	}
	va_end(ap);
	free(arg.fmt);
	return (arg.n_bytes);
}
