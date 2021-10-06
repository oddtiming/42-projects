#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	va_list		ap;
	static char	*output;
	char		*format_ptr;
	int			i;
	size_t		output_len;

	va_start(ap, format);
	i = 0;
	format_ptr = malloc(strlen_c(format, '%'));
	format_ptr = ft_strncpy(format_ptr, format, strlen_c(format, '%') - 1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			output = ft_strjoin_free(output, format_ptr);
			format_ptr = malloc(strlen_c(&format[i + 2], '%'));
			format_ptr = ft_strncpy(format_ptr, &format[i + 2], strlen_c(&format[i + 2], '%') - 1);
			i++;
			if (format[i] == 'c')
				output = ft_strjoin_free(output, c_to_s(va_arg(ap, int)));
			//NOTE THAT THE ABOVE WILL CAUSE A LEAK FROM c_to_s
			else if (format[i] == '%')
				output = ft_strjoin_free(output, "%");
			else if (format[i] == 's')
				output = ft_strjoin_free(output, va_arg(ap, char *));
			else if (is_set(format[i], "di"))
				output = ft_strjoin_free(output, ft_itoa(va_arg(ap, int)));
			//NOTE THAT THE ABOVE WILL CAUSE A LEAK FROM itoa
			else if (format[i] == 'p')
			{
				output = ft_strjoin_free(output, "0x");
				output = ft_strjoin_free(output, ft_hextoa((long)va_arg(ap, void *), format[i]));
			//NOTE THAT THE ABOVE WILL CAUSE A LEAK FROM hextoa
			}
			else if (is_set(format[i], "xX"))
				output = ft_strjoin_free(output, ft_hextoa_int(va_arg(ap, int), format[i]));
			//NOTE THAT THE ABOVE WILL CAUSE A LEAK FROM hextoa
			else if (format[i] == 'u')
				output = ft_strjoin_free(output, ft_itoa_unsigned(va_arg(ap, int)));
			//NOTE THAT THE ABOVE WILL CAUSE A LEAK FROM itoa_unsigned
		}
		i++;
	}
	va_end(ap);
	output = ft_strjoin_free(output, format_ptr);
	output_len = ft_strlen(output);
	write(1, output, output_len + 1);
	return (output_len);
}

int	main(void)
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
	return_value = ft_printf(format, i1, i1, i1, str1, str1, str2, 'c', str1, i1);
	printf("The return value is '%d'\n", return_value);
	return_value = printf(format, i1, i1, i1, str1, str1, str2, 'c', str1, i1);
	printf("The return value is '%d'\n", return_value);
	return (0);
}