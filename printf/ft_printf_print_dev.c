#include "ft_printf_bonus.h"

void	ft_printf_char_dev(t_arg *arg, char c)
{
	if (!(FLAG_WIDTH & arg->flags) || (FLAG_MINUS & arg->flags))
		arg->n_bytes += ft_putchar_ret(c);
	if ((FLAG_ZERO & arg->flags) && !(FLAG_MINUS & arg->flags))
		//Very bad practice of using var_type instead of declaring a new var
		arg->var_type = '0';
	else
		arg->var_type = ' ';
	while ((FLAG_WIDTH & arg->flags) && (arg->width-- > 1))
			arg->n_bytes += ft_putchar_ret(arg->var_type);
	if (!(FLAG_MINUS & arg->flags) && (FLAG_WIDTH & arg->flags))
		arg->n_bytes += ft_putchar_ret(c);
}

//Corrected the workflow so that no two copies of arg_to_str can be printed.
void	ft_printf_str_dev(t_arg *arg, char *arg_to_str)
{
	int		str_len;

	if (!arg_to_str)
		arg_to_str = ft_strdup("(null)");
	else
		arg_to_str = ft_strdup(arg_to_str);
	str_len = ft_strlen(arg_to_str);
	if ((FLAG_PREC & arg->flags) && arg->precision < str_len)
		str_len = arg->precision;
	arg->width -= str_len;
	while (!(FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
	arg->n_bytes += ft_putstr_n_ret(arg_to_str, str_len);
	while (arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
	free (arg_to_str);
}

void	ft_printf_nbr_dev(t_arg *arg, int nbr)
{
	int		str_len;

	str_len = ft_log_calc(nbr, 10);
	if ((FLAG_PREC & arg->flags) && (arg->precision > str_len))
		str_len = arg->precision;
	arg->width -= str_len;
	if (nbr < 0 || ((FLAG_PLUS | FLAG_SPACE) & arg->flags))
		arg->width--;
	while (!(FLAG_MINUS & arg->flags) && !((FLAG_ZERO & arg->flags) && \
		!(FLAG_PREC & arg->flags)) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
	if (nbr < 0)
	{
		arg->n_bytes += write(1, "-", 1);
		nbr = -nbr;
	}
	else if (arg->flags & FLAG_PLUS)
		arg->n_bytes += ft_putchar_ret('+');
	else if (arg->flags & FLAG_SPACE)
		arg->n_bytes += ft_putchar_ret(' ');
	while ((FLAG_ZERO & arg->flags) && \
		!((FLAG_MINUS + FLAG_PREC) & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, "0", 1);
	arg->n_bytes += ft_putnbr_unsigned_n_ret(nbr, str_len);
	while ((FLAG_MINUS & arg->flags) && (arg->width-- > 0))
		arg->n_bytes += write(1, " ", 1);
}

void	ft_printf_u_nbr_dev(t_arg *arg, unsigned int nbr)
{
	int		str_len;

	str_len = ft_log_calc_size_t(nbr, 10);
	if ((FLAG_PREC & arg->flags) && (arg->precision > str_len))
		str_len = arg->precision;
	arg->width -= str_len;
	// printf("In printf_u_nbr, flags = %s\n", byte_to_binary(arg->flags));
	//Very bad practice of using var_type instead of declaring a new var
	arg->var_type = ' ';
	//NOTE: is it true, or is the '0' flag ignored only if a precision is given
	if ((FLAG_ZERO & arg->flags) && !((FLAG_MINUS + FLAG_PREC) & arg->flags))
		arg->var_type = '0';
	// printf("before printing in printf_u_nbr, width = %d\n", arg->width);
	while (!(FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += ft_putchar_ret(arg->var_type);
	// printf("after args in printf_u_nbr, width = %d\n", arg->width);
	// printf("after '+ ' flags in printf_nbr, width = %d\n", arg->width);
	arg->n_bytes += ft_putnbr_unsigned_n_ret(nbr, str_len);
	while ((FLAG_MINUS & arg->flags) && (arg->width-- > 0))
		arg->n_bytes += write(1, " ", 1);
}

//added a condition so that # would only display when nbr != 0
void	ft_printf_hex_dev(t_arg *arg, unsigned int nbr)
{
	int	str_len;

	str_len = ft_log_calc_size_t(nbr, 16);
	if ((FLAG_PREC & arg->flags) && arg->precision > str_len)
		str_len = arg->precision;
	arg->width -= str_len;
	if (FLAG_HASH & arg->flags)
		arg->width -= 2;
	while (!(FLAG_MINUS & arg->flags) && !((FLAG_ZERO & arg->flags) && \
		!(FLAG_PREC & arg->flags)) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
	if ((FLAG_HASH & arg->flags) && arg->var_type == 'x' && nbr)
		arg->n_bytes += ft_putstr_ret("0x");
	else if ((FLAG_HASH & arg->flags) && arg->var_type == 'X' && nbr)
		arg->n_bytes += ft_putstr_ret("0X");
	while ((FLAG_ZERO & arg->flags) && \
		!((FLAG_MINUS + FLAG_PREC) & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, "0", 1);
	str_len = ft_log_calc_size_t(nbr, 16);
	while ((FLAG_PREC & arg->flags) && arg->precision-- > str_len)
		arg->n_bytes += write(1, "0", 1);
	ft_puthex_int(nbr, arg);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}

void	ft_printf_addr_dev(t_arg *arg, size_t addr)
{
	int	str_len;

	str_len = ft_log_calc_size_t(addr, 16);
	arg->width -= (str_len + 2);
	while (!(FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
	arg->n_bytes += ft_putstr_ret("0x");
	ft_puthex_size_t(arg, addr);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}