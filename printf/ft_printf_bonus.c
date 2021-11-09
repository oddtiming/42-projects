#include "ft_printf_bonus.h"

void	arg_num_value(t_arg *arg, va_list ap)
{
	int	num_value;

	if (arg->format[arg->index] == '*')
		num_value = va_arg(ap, int);
	else
	{
		num_value = ft_atoi(&arg->format[arg->index]);
		arg->index += ft_log_calc(num_value, 10) - 1;
	}
	if (FLAG_PREC & arg->flags)
	{
		arg->precision = num_value;
		if (num_value < 0)
			arg->flags &= ~FLAG_PREC;
	}
	else
	{
		if (num_value < 0)
		{
			num_value *= -1;
			arg->flags |= FLAG_MINUS;
		}
		arg->width = num_value;
		arg->flags |= FLAG_WIDTH;
	}
}

void	arg_parse_dev(t_arg *arg, va_list ap)
{
	int		flags_index[6] = {FLAG_MINUS, FLAG_ZERO, FLAG_PREC, FLAG_HASH, FLAG_SPACE, FLAG_PLUS};
	int		num_value;

	while (!is_set(arg->format[++arg->index], CONVERSIONS) \
		&& arg->format[arg->index])
	{
		num_value = is_set_ret(arg->format[arg->index], FLAGS);
		if (num_value != -1)
			arg->flags |= flags_index[num_value];
		else if ((arg->format[arg->index] >= '1' && \
			arg->format[arg->index] <= '9') || arg->format[arg->index] == '*')
			arg_num_value(arg, ap);
	}
	arg_dispatch(arg, ap);
}

	// arg->index += 1;
void	arg_dispatch(t_arg *arg, va_list ap)
{
	arg->var_type = arg->format[arg->index];
	if (arg->var_type == 'c')
		ft_printf_char_dev(arg, (char)va_arg(ap, int));
	else if (arg->var_type == 's')
		ft_printf_str_dev(arg, va_arg(ap, char *));
	else if (arg->var_type == 'p')
		ft_printf_addr_dev(arg, (size_t)va_arg(ap, void *));
	else if (is_set(arg->var_type, "di"))
		ft_printf_nbr_dev(arg, va_arg(ap, int));
	else if (arg->var_type == 'u')
		ft_printf_u_nbr_dev(arg, va_arg(ap, int));
	else if (is_set(arg->var_type, "xX"))
		ft_printf_hex_dev(arg, va_arg(ap, int));
	else if (arg->var_type == '%')
		ft_printf_char_dev(arg, '%');
	arg->index += 1;
}

	//NOTE: The struct needs to be reinitialized between every iteration 
	//of the loop to reset width etc.
	// That doesn't work when I remalloc the format everytime.
	// Could use a singleton function to initialize it only once, or a 
	//better idea would be to
	// have a separate struct for the format, index and var_type that would 
	//only be passed 
	// to arg_parse and arg_dispatch
int	ft_printf(char const *format, ...)
{
	va_list	ap;
	t_arg	arg;

	va_start(ap, format);
	printf_struct_init(&arg, format);
	while (format[arg.index])
	{
		if (format[arg.index] == '%')
		{
			arg_parse_dev(&arg, ap);
			printf_struct_reset(&arg);
		}
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
