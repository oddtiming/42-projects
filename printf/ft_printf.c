#include "ft_printf.h"

void	arg_parse(t_arg *arg)
{
	char	flags_arr[7] = {' ', '#', '+', '.', '0', '-', 0};
	int		flags_index[6] = {FLAG_SPACE, FLAG_HASH, FLAG_PLUS, FLAG_PRECISION, FLAG_ZERO, FLAG_MINUS};
	int		num_value;

	arg->index += 1;
	while (!is_set(arg->format[arg->index], CONVERSIONS) && arg->format[arg->index])
	{
		arg->flags |= flags_index[is_set_ret(arg->format[arg->index], flags_arr)];
		arg->index++;
		if (arg->format[arg->index] >= '1' && arg->format[arg->index]<= '9')
		{
			num_value = ft_atoi(&arg->format[arg->index]);
			if (arg->format[arg->index - 1] == '.')
				arg->precision = num_value;
			else
				arg->width = num_value;
			arg->index += get_magnitude(num_value);
		}
	}
	arg->var_type = arg->format[arg->index];
}

static void	arg_dispatch(t_arg *arg, va_list ap)
{
	arg->index += 1;
	arg->var_type = arg->format[arg->index];
	if (arg->var_type == 'c')
		arg->n_bytes += ft_putchar_ret((char)va_arg(ap, int));
	else if (arg->var_type == '%')
		arg->n_bytes += ft_putchar_ret('%');
	else if (arg->var_type == 's')
		arg->n_bytes += ft_putstr_ret(va_arg(ap, char *));
	else if (is_set(arg->var_type, "di"))
		arg->n_bytes += ft_putnbr_ret(va_arg(ap, int));
	else if (arg->var_type == 'u')
		arg->n_bytes += ft_putnbr_unsigned_ret(va_arg(ap, int));
	else if (arg->var_type == 'p')
	{
		arg->n_bytes += ft_putstr_ret("0x");
		ft_puthex_size_t((size_t)va_arg(ap, void *), arg);
	}
	else if (is_set(arg->var_type, "xX"))
		ft_puthex_int(va_arg(ap, int), arg);
	arg->index += 1;
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	t_arg	arg;

	va_start(ap, format);
	printf_struct_init(&arg, format);
	while (format[arg.index])
	{
		if (format[arg.index] == '%')
			arg_dispatch(&arg, ap);
		else
		{
			write(1, &format[arg.index], 1);
			arg.index += 1;
			arg.n_bytes += 1;
		}
	}
	va_end(ap);
	free(arg.format);
	return (arg.n_bytes);
}
/*	
 *	oct 18th 2021 todo
 *	List of proceedings:
 *	In ft_printf iterate through the string, if hit a % sign, pass to 
 *	printf_arg_parse;
 *	NOTE: width and precision are important variables, but meaningless as standalone, since we can have a width = 0 as an active
 *		, so a width flag needs to be set in addition to the 6 required flags.
 *		I also believe that width and precision are set as unsigned ints, since -1 gives the full length of any string with no warning
 *	else write(s[arg.index]; arg.index++; arg.n_bytes++;)
 *	printf_arg_parse will increment arg.index and instigate the corresponding flags and var_type, then call 
 *	printf_arg_dispatch that will call relevant function depending on the var_type.
 *	Each subfunction will increment arg.n_bytes.
 */

/*
 *	Notes oct 19th:
 *	- Important to review the validity of ft_printhex.c, remove any unused funstions, and try to reduce as much as possible the clutter of
 *		repetitive functions.
 *	Need to debug pointer's tests (for p = LONG_MAX and ULONG_MAX)
 */
/*
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
*/