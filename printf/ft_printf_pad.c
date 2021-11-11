#include "ft_printf_bonus.h"

/*
	Logical order of operations:
	1- Print the ' ' for width && no flags
	2- Print the modifiers ('+', '-', ' ', '0x', '0X')
		(could add a FLAG_NEG to know when to print the '-')
	3- Print the '0' for ((FLAG_ZERO & arg->flags) && !((FLAG_MINUS + FLAG_PREC) & arg->flags) && arg->width > 0)
	4- Print the converted argument
	5- Print the ' ' for width and FLAG_MINUS
*/

void	print_modifier(t_arg *arg)
{
	if (is_set(arg->var_type, "di"))
	{
		if (FLAG_NEG & arg->flags)
			arg->n_bytes += write(1, "-", 1);
		else if (FLAG_PLUS & arg->flags)
			arg->n_bytes += write(1, "+", 1);
		else if (FLAG_SPACE & arg->flags)
			arg->n_bytes += write(1, " ", 1);
	}
	else if ((arg->var_type == 'p') || (arg->var_type == 'x' && FLAG_HASH & arg->flags))
		arg->n_bytes += ft_putstr_ret("0x");
	else if (arg->var_type == 'X' && (FLAG_HASH & arg->flags))
		arg->n_bytes += ft_putstr_ret("0X");
	else if (arg->var_type == 'p')
		arg->n_bytes += ft_putstr_ret("0x");
}

void	pad_filler(t_arg *arg)
{
	while (!(FLAG_MINUS & arg->flags) && !((FLAG_ZERO & arg->flags) && \
		!(FLAG_PREC & arg->flags)) && arg->width > 0)
	{
		arg->n_bytes += write(1, " ", 1);
		arg->width--;
	}
	print_modifier(arg);
	while ((FLAG_ZERO & arg->flags) && \
		!((FLAG_MINUS + FLAG_PREC) & arg->flags) && arg->width > 0)
	{
		arg->n_bytes += write(1, "0", 1);
		arg->width--;
	}
}