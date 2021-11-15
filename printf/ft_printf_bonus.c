#include "ft_printf_bonus.h"

void	arg_num_value(t_arg *arg, va_list ap)
{
	int	num_value;

	//To add prec/width as a parameter
	if (arg->fmt[arg->index] == '*')
		num_value = va_arg(ap, int);
	//To add prec/width as a digit string before the conversion specifier
	else
	{
		num_value = ft_atoi(&arg->fmt[arg->index]);
		//log_calc to see how many digits num_value has. 
		//-1 because arg_parse() already increments arg->index
		arg->index += ft_log_calc(num_value, 10) - 1;
	}
	//If the string/* is added after a period, it is taken as precision
	if (FLAG_PREC & arg->flags)
	{
		arg->precision = num_value;
		//A negative precision argument is taken as if the precision were omitted.
		if (num_value < 0)
			arg->flags &= ~FLAG_PREC;
		//This is to stop the parsing if the num_value was to modify precision
		return ;
	}
	//Will only be reached if num_value does not modify precision, therefore if it modifies width
	//A negative field width argument is taken as a - flag followed by a positive field width
	if (num_value < 0)
	{
		num_value *= -1;
		arg->flags |= FLAG_MINUS;
	}
	arg->width = num_value;
}

void	arg_parse(t_arg *arg, va_list ap)
{
	int		flags_index[6];
	int		num_value;

	num_value = 0;
	//This is a hacky way to fill flags_index with corresponding flags;
	//see ft_printf_bonus.h for description of flags.
	while (num_value < 6)
	{
		//Incremental bit-shifting to set FLAGS
		flags_index[num_value] = 1 << num_value;
		num_value++;
	}
	//Hard-coded the values of possible strings to better imitate behaviour
	//of printf for chars that are not part of acceptable flags.
	while (is_set(arg->fmt[++arg->index], "-0.# +123456789*") \
		&& arg->fmt[arg->index])
	{
		//is_set_ret returns the index of a char if found in set
		num_value = is_set_ret(arg->fmt[arg->index], FLAGS);
		if (num_value != -1)
			arg->flags |= flags_index[num_value];
		//The conditions of this if statement suck balls, because it will treat
		//"%.0" as a FLAG_ZERO, but this is treated downstream in front_pad()
		else if ((arg->fmt[arg->index] >= '1' && \
			arg->fmt[arg->index] <= '9') || arg->fmt[arg->index] == '*')
			arg_num_value(arg, ap);
	}
	arg_dispatch(arg, ap);
}

void	arg_dispatch(t_arg *arg, va_list ap)
{
	arg->var_type = arg->fmt[arg->index];
	if (arg->var_type == 'c')
		ft_print_c(arg, (char)va_arg(ap, int));
	else if (arg->var_type == 's')
		ft_print_s(arg, va_arg(ap, char *));
	else if (arg->var_type == 'p')
		ft_print_p(arg, (size_t)va_arg(ap, void *));
	else if (is_set(arg->var_type, "di"))
		ft_print_di(arg, va_arg(ap, int));
	else if (arg->var_type == 'u')
		ft_print_u(arg, va_arg(ap, int));
	else if (is_set(arg->var_type, "xX"))
		ft_print_xX(arg, va_arg(ap, int));
	//To make sure that anything that isn't a valid modifier gets treated
	//as a %% conversion, just like printf does (albeit with a warning)
	else
		ft_print_c(arg, arg->var_type);
	//To return to the first character that is not part of a specifier
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
