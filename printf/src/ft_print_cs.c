#include "ft_printf.h"

void	ft_print_c(t_arg *arg, char c)
{
	//To account for the size of the character
	arg->width -= 1;
	front_pad(arg);
	arg->n_bytes += write(1, &c, 1);
	//Prints out the padding for FLAG_MINUS
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}

void	ft_print_s(t_arg *arg, char *arg_to_str)
{
	int		str_len;

	//to emulate printf behaviour
	if (!arg_to_str)
		arg_to_str = ft_strdup("(null)");
	//The strdup is not necessary, but useful to avoid conditions for free()
	else
		arg_to_str = ft_strdup(arg_to_str);
	str_len = ft_strlen(arg_to_str);
	//Adjust str_len if precision restricts the amount of chars to print
	if ((FLAG_PREC & arg->flags) && arg->precision < str_len)
		str_len = arg->precision;
	arg->width -= str_len;
	front_pad(arg);
	arg->n_bytes += ft_putstr_n_ret(arg_to_str, str_len);
	//Prints out the padding for FLAG_MINUS
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
	free (arg_to_str);
}
