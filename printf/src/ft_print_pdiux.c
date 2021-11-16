#include "ft_printf.h"

void	ft_print_di(t_arg *arg, int nbr)
{
	int		str_len;

	//Determines the number of chars to be printed	
	str_len = ft_log_calc(nbr, 10);
	//Adjusts the width if prec > str_len
	if ((FLAG_PREC & arg->flags) && arg->precision > str_len)
		str_len = arg->precision;
	//The dumbest if statement of all time ; only to take care of
	//not printing anything when prec == 0 and nbr == 0
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))	
		arg->width -= str_len;
	//If a modifier needs to be printed, reduce width by 1
	if (nbr < 0 || ((FLAG_PLUS | FLAG_SPACE) & arg->flags))
		arg->width--;
	//I use FLAG_NEG to output a '-' before negative numbers, 
	//therefore I can treat negative numbers as unsigned.
	if (nbr < 0)
	{
		arg->flags |= FLAG_NEG;
		nbr = -nbr;
	}
	front_pad(arg);
	//Does not print if nbr == 0 and prec == 0
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		arg->n_bytes += ft_putnbr_unsigned_n_ret(nbr, str_len);
	//Prints out the padding for FLAG_MINUS
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}

void	ft_print_u(t_arg *arg, unsigned int nbr)
{
	int		str_len;

	//Determines the number of chars to be printed	
	str_len = ft_log_calc_size_t(nbr, 10);
	//Adjusts the width if prec > str_len
	if ((FLAG_PREC & arg->flags) && (arg->precision > str_len))
		str_len = arg->precision;
	//The dumbest if statement of all time ; only to take care of
	//not printing anything when prec == 0 and nbr == 0
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))	
		arg->width -= str_len;
	front_pad(arg);
	//Does not print if nbr == 0 and prec == 0
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		arg->n_bytes += ft_putnbr_unsigned_n_ret(nbr, str_len);
	//Prints out the padding for FLAG_MINUS
	while ((FLAG_MINUS & arg->flags) && (arg->width-- > 0))
		arg->n_bytes += write(1, " ", 1);
}

void	ft_print_x(t_arg *arg, unsigned int nbr)
{
	int	str_len;

	//Determines the number of chars to be printed	
	str_len = ft_log_calc_size_t(nbr, 16);
	//Adjusts the width if prec > str_len
	if ((FLAG_PREC & arg->flags) && arg->precision > str_len)
		str_len = arg->precision;
	//The dumbest if statement of all time ; only to take care of
	//not printing anything when prec == 0 and nbr == 0
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		arg->width -= str_len;
	//If nbr == 0, '#' flag does nothing
	if (!nbr)
		arg->flags &= ~FLAG_HASH;
	//Saves space in width for '0{x, X}' if '#' flag is present
	if (FLAG_HASH & arg->flags)
		arg->width -= 2;
	front_pad(arg);
	//Readjusts str_len in case prec > str_len
	str_len = ft_log_calc_size_t(nbr, 16);
	//Since puthex is recursive, I handle precision inside this function
	while ((FLAG_PREC & arg->flags) && arg->precision > str_len)
	{
		arg->n_bytes += write(1, "0", 1);
		arg->precision--;
	}
	//Does not print if nbr == 0 and prec == 0
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		ft_puthex_size_t(arg, nbr);
	//Prints out the padding for FLAG_MINUS
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}

void	ft_print_p(t_arg *arg, size_t addr)
{
	int	str_len;

	//Determines the number of chars to be printed	
	str_len = ft_log_calc_size_t(addr, 16);
	//Adjusts the width if prec > str_len
	if ((FLAG_PREC & arg->flags) && arg->precision > str_len)
		str_len = arg->precision;
	//Does not adjust width if nothing is printed (nbr == 0 && prec == 0)
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !addr))
		arg->width -= (str_len);
	//Saves space in width for '0x'
	arg->width -= 2;
	front_pad(arg);
	//Readjusts str_len in case prec > str_len
	str_len = ft_log_calc_size_t(addr, 16);
	//Since puthex is recursive, I handle precision inside this function
	//Not necessary nor relevant, since prec with 'p' --> UB
	while ((FLAG_PREC & arg->flags) && arg->precision > str_len)
	{
		arg->n_bytes += write(1, "0", 1);
		arg->precision--;
	}
	//Does not print if nbr == 0 and prec == 0
	//Not necessary nor relevant, since prec with 'p' --> UB
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !addr))
		ft_puthex_size_t(arg, addr);
	//Prints out the padding for FLAG_MINUS
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}
