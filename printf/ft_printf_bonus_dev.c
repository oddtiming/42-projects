#include "ft_printf_bonus.h"

void	arg_parse(t_arg *arg, va_list ap)
{
//	char	flags_arr[7] = {'-', '0', '.', '#', ' ', '+', 0};
	int		flags_index[6] = {FLAG_MINUS, FLAG_ZERO, FLAG_PREC, FLAG_HASH, FLAG_SPACE, FLAG_PLUS};
	int		(*fct[9])(va_list, t_arg*) = {ft_putchar_ret, ft_putstr_ret, ft_puthex_size_t, ft_putnbr_ret, ft_putnbr_ret, ft_putnbr_ret, ft_puthex_int, ft_putchar_ret};
	int		num_value;

	while (!is_set(arg->format[++arg->index], CONVERSIONS) && arg->format[arg->index])
	{
		// num_value = is_set_ret(arg->format[arg->index], flags_arr);
		num_value = is_set_ret(arg->format[arg->index], FLAGS);
		if (num_value != -1)
			arg->flags |= flags_index[num_value];
		else if (arg->format[arg->index] >= '1' && arg->format[arg->index]<= '9')
		{
			num_value = ft_atoi(&arg->format[arg->index]);
			if (FLAG_PREC & arg->flags)
				arg->precision = num_value;
			else
			{
				arg->width = num_value;
				arg->flags |= FLAG_WIDTH;
			}
			arg->index += ft_log_calc(num_value, 10) - 1;
		}
	}
	arg->var_type = arg->format[arg->index];
	arg->n_bytes += fct[is_set_ret(arg->var_type, CONVERSIONS)](ap, arg);
}

void	arg_parse_dev(t_arg *arg, va_list ap)
{
//	char	flags_arr[7] = {'-', '0', '.', '#', ' ', '+', 0};
	int		flags_index[6] = {FLAG_MINUS, FLAG_ZERO, FLAG_PREC, FLAG_HASH, FLAG_SPACE, FLAG_PLUS};
	int		num_value;

	while (!is_set(arg->format[++arg->index], CONVERSIONS) && arg->format[arg->index])
	{
		// num_value = is_set_ret(arg->format[arg->index], flags_arr);
		num_value = is_set_ret(arg->format[arg->index], FLAGS);
		if (num_value != -1)
			arg->flags |= flags_index[num_value];
		else if (arg->format[arg->index] >= '1' && arg->format[arg->index]<= '9')
		{
			num_value = ft_atoi(&arg->format[arg->index]);
			if (FLAG_PREC & arg->flags)
				arg->precision = num_value;
			else
			{
				arg->width = num_value;
				arg->flags |= FLAG_WIDTH;
			}
			arg->index += ft_log_calc(num_value, 10) - 1;
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
	else if (arg->var_type == 's')
		arg->n_bytes += ft_putstr_ret(va_arg(ap, char *));
	else if (arg->var_type == 'p')
	{
		arg->n_bytes += ft_putstr_ret("0x");
		ft_puthex_size_t((size_t)va_arg(ap, void *), arg);
	}
	else if (is_set(arg->var_type, "di"))
		arg->n_bytes += ft_putnbr_ret(va_arg(ap, int));
	else if (arg->var_type == 'u')
		arg->n_bytes += ft_putnbr_unsigned_ret(va_arg(ap, int));
	else if (is_set(arg->var_type, "xX"))
		ft_puthex_int(va_arg(ap, int), arg);
	else if (arg->var_type == '%')
		arg->n_bytes += ft_putchar_ret('%');
	arg->index += 1;
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	t_arg	arg;

	va_start(ap, format);
	//NOTE: The struct needs to be reinitialized between every iteration of the loop to reset width etc.
	// That doesn't work when I remalloc the format everytime.
	// Could use a singleton function to initialize it only once, or a better idea would be to
	// have a separate struct for the format, index and var_type that would only be passed 
	// to arg_parse and arg_dispatch
	printf_struct_init(&arg, format);
	while (format[arg.index])
	{
		if (format[arg.index] == '%')
			arg_parse(&arg, ap);
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
