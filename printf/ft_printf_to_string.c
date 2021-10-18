#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	static char	*output;
	char		*format_ptr;
	char		*str_temp;
	int			i;
	size_t		output_len;

	va_start(ap, format);
	i = 0;
	format_ptr = malloc(strlen_c((char *)format, '%'));
	format_ptr = ft_strncpy(format_ptr, (char *)format, strlen_c((char *)format, '%') - 1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			output = ft_strjoin_dbfree(output, format_ptr);
			format_ptr = malloc(strlen_c((char *)&format[i + 2], '%'));
			format_ptr = ft_strncpy(format_ptr, (char *)&format[i + 2], strlen_c((char *)&format[i + 2], '%') - 1);
			i++;
			//NOTE: 'c' doit gérer les cas où c == 0. Retourner la bonne valeur, mais aussi imprimer la bonne chose
			//needs testing
			if (format[i] == 'c')
				output = ft_strjoin_dbfree(output, c_to_s(va_arg(ap, int)));
			else if (format[i] == '%')
				output = ft_strjoin_free(output, "%");
			else if (format[i] == 's')
			{
				str_temp = va_arg(ap, char *);
				if (str_temp)
					output = ft_strjoin_free(output, str_temp);
				else
					output = ft_strjoin_free(output, "(null)");
			}
			else if (is_set(format[i], "di"))
				output = ft_strjoin_dbfree(output, ft_itoa(va_arg(ap, int)));
			else if (format[i] == 'p')
			{
				output = ft_strjoin_free(output, "0x");
				output = ft_strjoin_dbfree(output, ft_hextoa((long)va_arg(ap, void *), format[i]));
			}
			else if (is_set(format[i], "xX"))
				output = ft_strjoin_dbfree(output, ft_hextoa_int(va_arg(ap, int), format[i]));
			else if (format[i] == 'u')
				output = ft_strjoin_dbfree(output, ft_itoa_unsigned(va_arg(ap, int)));
		}
		i++;
	}
	va_end(ap);
	output = ft_strjoin_free(output, format_ptr);
	output_len = ft_strlen(output);
	write(1, output, output_len + 1);
	free (output);
	free(format_ptr);
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
