#include "ft_printf.h"

static void	arg_dispatch(t_arg *holder, va_list ap)
{
	holder->index += 1;
	holder->var_type = holder->format[holder->index];
	if (holder->var_type == 'c')
		holder->n_bytes += ft_putchar_ret((char)va_arg(ap, int));
	else if (holder->var_type == '%')
		holder->n_bytes += ft_putchar_ret('%');
	else if (holder->var_type == 's')
		holder->n_bytes += ft_putstr_ret(va_arg(ap, char *));
	else if (is_set(holder->var_type, "di"))
		holder->n_bytes += ft_putnbr_ret(va_arg(ap, int));
	else if (holder->var_type == 'u')
		holder->n_bytes += ft_putnbr_unsigned_ret(va_arg(ap, int));
	else if (holder->var_type == 'p')
	{
		holder->n_bytes += ft_putstr_ret("0x");
		ft_puthex_size_t((size_t)va_arg(ap, void *), holder);
	}
	else if (is_set(holder->var_type, "xX"))
		ft_puthex_int(va_arg(ap, int), holder);
	holder->index += 1;
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	t_arg	holder;

	va_start(ap, format);
	printf_struct_init(&holder, format);
	while (format[holder.index])
	{
		if (format[holder.index] == '%')
			arg_dispatch(&holder, ap);
		else
		{
			write(1, &format[holder.index], 1);
			holder.index += 1;
			holder.n_bytes += 1;
		}
	}
	va_end(ap);
	free(holder.format);
	return (holder.n_bytes);
}
/*	
 *	oct 18th 2021 todo
 *	List of proceedings:
 *	In ft_printf iterate through the string, if hit a % sign, pass to 
 *	printf_arg_parse;
 *	NOTE: width and precision are important variables, but meaningless as standalone, since we can have a width = 0 as an active
 *		, so a width flag needs to be set in addition to the 6 required flags.
 *		I also believe that width and precision are set as unsigned ints, since -1 gives the full length of any string with no warning
 *	else write(s[holder.index]; holder.index++; holder.n_bytes++;)
 *	printf_arg_parse will increment holder.index and instigate the corresponding flags and var_type, then call 
 *	printf_arg_dispatch that will call relevant function depending on the var_type.
 *	Each subfunction will increment holder.n_bytes.
 */

/*
 *	Notes oct 19th:
 *	- Important to review the validity of ft_printhex.c, remove any unused funstions, and try to reduce as much as possible the clutter of
 *		repetitive functions.
 *	Need to debug pointer's tests (for p = LONG_MAX and ULONG_MAX)
 */

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
	return_value = ft_printf(format, i1, i1, i1, str1, str1, str2, 0, str1, i1);
	printf("The return value of ft_printf is '%d'\n", return_value);
	return_value = printf(format, i1, i1, i1, str1, str1, str2, 0, str1, i1);
	printf("The return value of printf is '%d'\n", return_value);
	return (0);
}
