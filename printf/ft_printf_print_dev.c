#include "ft_printf_bonus.h"

void	ft_printf_char_dev(t_arg *arg, char c)
{
	arg->width--;
	pad_filler(arg);
	arg->n_bytes += write(1, &c, 1);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}

//Corrected the workflow so that no two copies of arg_to_str can be printed.
	// printf("in printf_str, arg_to_str = '%s'\n", arg_to_str);
	// printf("arg->flags = %s\n", byte_to_binary(arg->flags));
	// printf("arg->precision = %d\n", arg->precision);
	// printf("arg->width = %d\n", arg->width);
void	ft_printf_str_dev(t_arg *arg, char *arg_to_str)
{
	int		str_len;

	if (!arg_to_str)
		arg_to_str = ft_strdup("(null)");
	else
		arg_to_str = ft_strdup(arg_to_str);
	str_len = ft_strlen(arg_to_str);
	//Added arg->precision >= 0 for cases where prec < 0 (when '.*' is used)
	if ((FLAG_PREC & arg->flags) && arg->precision < str_len && arg->precision >= 0)
		str_len = arg->precision;
	arg->width -= str_len;
	pad_filler(arg);
	arg->n_bytes += ft_putstr_n_ret(arg_to_str, str_len);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
	free (arg_to_str);
}

void	ft_printf_nbr_dev(t_arg *arg, int nbr)
{
	int		str_len;

	str_len = ft_log_calc(nbr, 10);
	if ((FLAG_PREC & arg->flags) && (arg->precision > str_len))
		str_len = arg->precision;
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))	
		arg->width -= str_len;
	if (nbr < 0 || ((FLAG_PLUS | FLAG_SPACE) & arg->flags))
		arg->width--;
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

void	ft_printf_u_nbr_dev(t_arg *arg, unsigned int nbr)
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
void	ft_printf_hex_dev(t_arg *arg, unsigned int nbr)
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
		ft_puthex_int(nbr, arg);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}

void	ft_printf_addr_dev(t_arg *arg, size_t addr)
{
	int	str_len;

	str_len = ft_log_calc_size_t(addr, 16);
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !addr))
		arg->width -= (str_len);
	arg->width -= 2;
	pad_filler(arg);
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !addr))
		ft_puthex_size_t(arg, addr);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}