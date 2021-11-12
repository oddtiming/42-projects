#include "ft_printf_bonus.h"

void	ft_print_c(t_arg *arg, char c)
{
	//To account for the size of the character
	arg->width -= 1;
	pad_filler(arg);
	arg->n_bytes += write(1, &c, 1);
	//To print out the padding for FLAG_MINUS
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
	pad_filler(arg);
	arg->n_bytes += ft_putstr_n_ret(arg_to_str, str_len);
	//To print out the padding for FLAG_MINUS
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
	free (arg_to_str);
}

void	ft_print_di(t_arg *arg, int nbr)
{
	int		str_len;

	str_len = ft_log_calc(nbr, 10);
	//Precision being bigger than the amount of digits required
	//necessitates a concurrent adjustment to the width
	if ((FLAG_PREC & arg->flags) && arg->precision > str_len)
		str_len = arg->precision;
	//The dumbest if statement of all time ; only to take care of
	//not printing anything when prec == 0 and nbr == 0
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))	
		arg->width -= str_len;
	//If a modifier needs to be printed, reduce width by 1
	if (nbr < 0 || ((FLAG_PLUS | FLAG_SPACE) & arg->flags))
		arg->width--;
	//I use FLAG_MINUS to output a '-' before negative numbers, therefore
	//I can treat negative numbers as unsigned.
	if (nbr < 0)
	{
		arg->flags |= FLAG_NEG;
		nbr = -nbr;
	}
	pad_filler(arg);
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		arg->n_bytes += ft_putnbr_unsigned_n_ret(nbr, str_len);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}

void	ft_print_u(t_arg *arg, unsigned int nbr)
{
	int		str_len;

	str_len = ft_log_calc_size_t(nbr, 10);
	if ((FLAG_PREC & arg->flags) && (arg->precision > str_len))
		str_len = arg->precision;
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))	
		arg->width -= str_len;
	pad_filler(arg);
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		arg->n_bytes += ft_putnbr_unsigned_n_ret(nbr, str_len);
	while ((FLAG_MINUS & arg->flags) && (arg->width-- > 0))
		arg->n_bytes += write(1, " ", 1);
}

//added a condition so that # would only display when nbr != 0
	// printf("after flag_hash, arg->width = %d\n", arg->width);
	// printf("before ft_puthex_int, arg->width = %d\n", arg->width);
	// printf("after first if, arg->width = %d\n", arg->width);
void	ft_print_xX(t_arg *arg, unsigned int nbr)
{
	int	str_len;
	
	str_len = ft_log_calc_size_t(nbr, 16);
	if ((FLAG_PREC & arg->flags) && arg->precision > str_len)
		str_len = arg->precision;
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		arg->width -= str_len;
	//Could be added to flag_correction
	if (!nbr)
		arg->flags &= ~FLAG_HASH;
	if (FLAG_HASH & arg->flags)
		arg->width -= 2;
	pad_filler(arg);
	str_len = ft_log_calc_size_t(nbr, 16);
	while ((FLAG_PREC & arg->flags) && arg->precision > str_len)
	{
		arg->n_bytes += write(1, "0", 1);
		arg->precision--;
	}
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		ft_puthex_size_t(arg, nbr);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}

void	ft_print_p(t_arg *arg, size_t addr)
{
	int	str_len;

	str_len = ft_log_calc_size_t(addr, 16);
	if ((FLAG_PREC & arg->flags) && arg->precision > str_len)
		str_len = arg->precision;
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !addr))
		arg->width -= (str_len);
	arg->width -= 2;
	pad_filler(arg);
	str_len = ft_log_calc_size_t(addr, 16);
	while ((FLAG_PREC & arg->flags) && arg->precision > str_len)
	{
		arg->n_bytes += write(1, "0", 1);
		arg->precision--;
	}
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !addr))
		ft_puthex_size_t(arg, addr);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}
