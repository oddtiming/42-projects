#include "ft_printf_bonus.h"

//Here the idea is simply to print all the blank characters/zeros before or after the character
void	ft_printf_char(t_arg *arg, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	if ((FLAG_WIDTH & arg->flags) == 0)
	{
		arg->n_bytes += ft_putchar_ret(c);
		return ;
	}
	arg->n_bytes += arg->width;
	if (FLAG_MINUS & arg->flags)
	{
		write(1, &c, 1);
		arg->width--;
		while (arg->width--)
			write(1, " ", 1);
	}
	while (arg->width-- > 1)
	{
		if (FLAG_ZERO & arg->flags)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	if (arg->width)
		write(1, &c, 1);
}

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

void	ft_printf_str(t_arg *arg, va_list ap)
{
	char	*arg_to_str;
	int		str_len;

	arg_to_str = ft_strdup(va_arg(ap, char *));
	if (!arg_to_str)
		arg_to_str = ft_strdup("(null)");
	if (FLAG_PREC & arg->flags)

	str_len = ft_strlen(arg_to_str);
	
}

void	ft_printf_str_dev(t_arg *arg, char *arg_to_str)
{
	int		str_len;

	if (!arg_to_str)
		arg_to_str = ft_strdup("(null)");
	else
		arg_to_str = ft_strdup(arg_to_str);
	str_len = ft_strlen(arg_to_str);
	if (FLAG_PREC & arg->flags && arg->precision < str_len)
		str_len = arg->precision;
	if (str_len >= arg->width || (FLAG_MINUS & arg->flags))
		arg->n_bytes += ft_putstr_n_ret(arg_to_str, str_len);
	arg->width -= str_len;
	if ((FLAG_ZERO & arg->flags) && !(FLAG_MINUS & arg->flags))
		//Very bad practice of using var_type instead of declaring a new var
		arg->var_type = '0';
	else
		arg->var_type = ' ';
	while (arg->width--)
		arg->n_bytes += ft_putchar_ret(arg->var_type);
	if (!(FLAG_MINUS & arg->flags))
		arg->n_bytes += ft_putstr_n_ret(arg_to_str, str_len);
	free (arg_to_str);
}

void	ft_printf_nbr(t_arg *arg, va_list ap)
{
	
}

//DOESN'T WORK!!!
//For flags '0', '+' and ' ', the 0s need to be appended between the sign and the number
//This is a cluster fuck
void	ft_printf_nbr_dev(t_arg *arg, int nbr)
{
	int		str_len;

	str_len = ft_log_calc(nbr, 10);
	write(1, "\"", 1);
	if ((FLAG_PREC & arg->flags) && (arg->precision > str_len))
		str_len = arg->precision;
	arg->width -= str_len;
	//The width needs to be adjusted based on whether '+', '-', or ' ' was printed in subfct
	//DONE
	if (nbr < 0 || ((FLAG_PLUS | FLAG_SPACE) & arg->flags))
		arg->width--;
	// printf("In printf_nbr, flags = %s\n", byte_to_binary(arg->flags));
	// printf("before printing in printf_nbr, width = %d\n", arg->width);
	while (!(FLAG_MINUS & arg->flags) && !((FLAG_ZERO & arg->flags) && \
		!(FLAG_PREC & arg->flags)) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
	// printf("after args in printf_nbr, width = %d\n", arg->width);
	if (nbr < 0 || ((FLAG_PLUS | FLAG_SPACE) & arg->flags))
	{
		if (nbr < 0)
		{
			arg->n_bytes += write(1, "-", 1);
			nbr = -nbr;
		}
		else if (arg->flags & FLAG_PLUS)
			arg->n_bytes += ft_putchar_ret('+');
		else if ((arg->flags & FLAG_SPACE) || (!(FLAG_MINUS & arg->flags) && arg->width > 0))
			arg->n_bytes += ft_putchar_ret(' ');
	}
	while ((FLAG_ZERO & arg->flags) && \
		!((FLAG_MINUS + FLAG_PREC) & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, "0", 1);
	// printf("after '+ ' flags in printf_nbr, width = %d\n", arg->width);
	arg->n_bytes += ft_putnbr_unsigned_n_ret(nbr, str_len);
	while ((FLAG_MINUS & arg->flags) && (arg->width-- > 0))
		arg->n_bytes += write(1, " ", 1);
	write(1, "\"", 1);
}

void	ft_printf_u_nbr(t_arg *arg, va_list ap)
{
	
}

void	ft_printf_u_nbr_dev(t_arg *arg, unsigned int nbr)
{
	int		str_len;

	str_len = ft_log_calc_size_t(nbr, 10);
	write(1, "\"", 1);
	if ((FLAG_PREC & arg->flags) && (arg->precision > str_len))
		str_len = arg->precision;
	arg->width -= str_len;
	// printf("In printf_u_nbr, flags = %s\n", byte_to_binary(arg->flags));
	//Very bad practice of using var_type instead of declaring a new var
	arg->var_type = ' ';
	//The hex number represents, from right to left, FLAG_MINUS, FLAG_SPACE, and FLAG_PLUS
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
	write(1, "\"", 1);
}

void	ft_printf_hex(t_arg *arg, va_list ap)
{
	
}

void	ft_printf_hex_dev(t_arg *arg, unsigned int nbr)
{
	int	str_len;

	write(1, "\"", 1);
	str_len = ft_log_calc_size_t(nbr, 16);
	if ((FLAG_PREC & arg->flags) && arg->precision > str_len)
		str_len = arg->precision;
	arg->width -= str_len;
	if (FLAG_HASH & arg->flags)
		arg->width -= 2;
	while (!(FLAG_MINUS & arg->flags) && !((FLAG_ZERO & arg->flags) && \
		!(FLAG_PREC & arg->flags)) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
	if ((FLAG_HASH & arg->flags) && arg->var_type == 'x')
		arg->n_bytes += ft_putstr_ret("0x");
	else if ((FLAG_HASH & arg->flags) && arg->var_type == 'X')
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
	write(1, "\"", 1);
}

void	ft_printf_addr(t_arg *arg, va_list ap)
{
	
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

void	puthex_tester(void)
{
	t_arg	arg;
	int		return_value;
	int		nbr = 12345;

	arg.width = 7;
	arg.precision = 7;
	// arg.flags |= FLAG_MINUS;
	// arg.flags |= FLAG_ZERO;
	arg.flags |= FLAG_PREC;
	arg.flags |= FLAG_WIDTH;
	arg.n_bytes = 0;
	arg.var_type = 'x';

	printf("------Tests for ft_printf_puthex------\n");
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("The real printf: \n");
	return_value = printf("\"%*.*x\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("The real printf: \n");
	return_value = printf("\"%*.*x\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 0;
	arg.flags &= ~FLAG_PREC;
	nbr = INT_MIN;
	printf("for width = %1$d and d = %2$d\n", arg.width, nbr);
	printf("The real printf: \n");
	return_value = printf("\"%*x\"", arg.width,  nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_PREC;
	arg.flags |= FLAG_PLUS;
	nbr = 10;
	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '+' FLAG\n");
	printf("arg.flags = %s\n", byte_to_binary(arg.flags));
	printf("The real printf: \n");
	return_value = printf("\"%+*.*x\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_PLUS;
	arg.flags |= FLAG_SPACE;
	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"% *.*x\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_PLUS;
	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '+' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%+ *.*x\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_SPACE;
	arg.flags |= FLAG_ZERO;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '+' and '0' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%0+*.*x\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_PLUS;
	arg.flags |= FLAG_SPACE;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '0' FLAGS\n");
	printf("arg.flags = %s\n", byte_to_binary(arg.flags));
	printf("The real printf: \n");
	return_value = printf("\"%0 *.*x\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_MINUS;
	arg.flags &= ~FLAG_ZERO;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '-' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"% -*.*x\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_SPACE;
	arg.flags |= FLAG_HASH;	
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '#' and '-' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%#-*.*x\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 9;
	nbr = -32;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '#' and '-' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%#-*.*x\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_HASH;
	arg.flags &= ~FLAG_MINUS;
	arg.flags &= ~FLAG_PREC;
	arg.flags |= FLAG_ZERO;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	nbr = 42;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '0' FLAGS && NO PRECISION\n");
	printf("The real printf: \n");
	return_value = printf("\"%0*x\"", arg.width, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_HASH;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	nbr = 42;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '#' and '0' FLAGS && NO PRECISION\n");
	printf("The real printf: \n");
	return_value = printf("\"%#0*x\"", arg.width, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.width = 20;
	arg.n_bytes = 0;
	nbr = -42;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '#' and '0' FLAGS && NO PRECISION\n");
	printf("The real printf: \n");
	return_value = printf("\"%#0*x\"", arg.width, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_hex_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);
}

void	putnbr_u_tester(void)
{
	t_arg	arg;
	int		return_value;
	int		nbr = 12345;

	arg.width = 7;
	arg.precision = 7;
	// arg.flags |= FLAG_MINUS;
	// arg.flags |= FLAG_ZERO;
	arg.flags |= FLAG_PREC;
	arg.flags |= FLAG_WIDTH;
	arg.n_bytes = 0;

	printf("------Tests for ft_printf_putnbr------\n");
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("The real printf: \n");
	return_value = printf("\"%*.*u\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("The real printf: \n");
	return_value = printf("\"%*.*u\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 0;
	arg.flags &= ~FLAG_PREC;
	nbr = INT_MIN;
	printf("for width = %1$d and d = %2$d\n", arg.width, nbr);
	printf("The real printf: \n");
	return_value = printf("\"%*u\"", arg.width,  nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_PREC;
	arg.flags |= FLAG_PLUS;
	nbr = 10;
	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '+' FLAG\n");
	printf("arg.flags = %s\n", byte_to_binary(arg.flags));
	printf("The real printf: \n");
	return_value = printf("\"%+*.*u\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_PLUS;
	arg.flags |= FLAG_SPACE;
	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"% *.*u\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_PLUS;
	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '+' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%+ *.*u\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_SPACE;
	arg.flags |= FLAG_ZERO;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '+' and '0' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%0+*.*u\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_PLUS;
	arg.flags |= FLAG_SPACE;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '0' FLAGS\n");
	printf("arg.flags = %s\n", byte_to_binary(arg.flags));
	printf("The real printf: \n");
	return_value = printf("\"%0 *.*u\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_MINUS;
	arg.flags &= ~FLAG_ZERO;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '-' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"% -*.*u\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_SPACE;
	arg.flags |= FLAG_PLUS;	
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '+' and '-' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%+-*.*u\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	nbr = -32;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '+' and '-' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%+-*.*u\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_PLUS;
	arg.flags &= ~FLAG_MINUS;
	arg.flags &= ~FLAG_PREC;
	arg.flags |= FLAG_ZERO;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	nbr = 42;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '0' FLAGS && NO PRECISION\n");
	printf("The real printf: \n");
	return_value = printf("\"%0*u\"", arg.width, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_SPACE;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	nbr = 42;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '0' FLAGS && NO PRECISION\n");
	printf("The real printf: \n");
	return_value = printf("\"% 0*u\"", arg.width, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.width = 20;
	arg.n_bytes = 0;
	nbr = -42;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '0' FLAGS && NO PRECISION\n");
	printf("The real printf: \n");
	return_value = printf("\"% 0*u\"", arg.width, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_u_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);
}

void	putnbr_tester(void)
{
	t_arg	arg;
	int		return_value;
	int		nbr = 12345;

	arg.width = 7;
	arg.precision = 7;
	// arg.flags |= FLAG_MINUS;
	// arg.flags |= FLAG_ZERO;
	arg.flags |= FLAG_PREC;
	arg.flags |= FLAG_WIDTH;
	arg.n_bytes = 0;

	printf("------Tests for ft_printf_putnbr------\n");
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("The real printf: \n");
	return_value = printf("\"%*.*d\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("The real printf: \n");
	return_value = printf("\"%*.*d\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 0;
	arg.flags &= ~FLAG_PREC;
	nbr = INT_MIN;
	printf("for width = %1$d and d = %2$d\n", arg.width, nbr);
	printf("The real printf: \n");
	return_value = printf("\"%*d\"", arg.width,  nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_PREC;
	arg.flags |= FLAG_PLUS;
	nbr = 10;
	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '+' FLAG\n");
	printf("arg.flags = %s\n", byte_to_binary(arg.flags));
	printf("The real printf: \n");
	return_value = printf("\"%+*.*d\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_PLUS;
	arg.flags |= FLAG_SPACE;
	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"% *.*d\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_PLUS;
	arg.n_bytes = 0;
	arg.width = 0;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '+' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%+ *.*d\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_SPACE;
	arg.flags |= FLAG_ZERO;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '+' and '0' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%0+*.*d\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_PLUS;
	arg.flags |= FLAG_SPACE;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '0' FLAGS\n");
	printf("arg.flags = %s\n", byte_to_binary(arg.flags));
	printf("The real printf: \n");
	return_value = printf("\"%0 *.*d\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_MINUS;
	arg.flags &= ~FLAG_ZERO;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '-' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"% -*.*d\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_SPACE;
	arg.flags |= FLAG_PLUS;	
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '+' and '-' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%+-*.*d\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	nbr = -32;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '+' and '-' FLAGS\n");
	printf("The real printf: \n");
	return_value = printf("\"%+-*.*d\"", arg.width, arg.precision, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_PLUS;
	arg.flags &= ~FLAG_MINUS;
	arg.flags &= ~FLAG_PREC;
	arg.flags |= FLAG_ZERO;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	nbr = 42;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '0' FLAGS && NO PRECISION\n");
	printf("The real printf: \n");
	return_value = printf("\"%0*d\"", arg.width, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags |= FLAG_SPACE;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	nbr = 42;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '0' FLAGS && NO PRECISION\n");
	printf("The real printf: \n");
	return_value = printf("\"% 0*d\"", arg.width, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.flags &= ~FLAG_SPACE;
	arg.flags |= FLAG_PLUS;
	arg.n_bytes = 0;
	arg.width = 20;
	arg.precision = 10;
	nbr = 42;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH '+' and '0' FLAGS && NO PRECISION\n");
	printf("The real printf: \n");
	return_value = printf("\"%+0*d\"", arg.width, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);

	arg.width = 20;
	arg.n_bytes = 0;
	nbr = -42;
	printf("for width = %1$d and prec = %2$d and d = %3$d\n", arg.width, arg.precision, nbr);
	printf("WITH ' ' and '0' FLAGS && NO PRECISION\n");
	printf("The real printf: \n");
	return_value = printf("\"% 0*d\"", arg.width, nbr);
	printf("\nreturn value = %d\n", return_value - 2);
	printf("ft_printf: \n");
	ft_printf_nbr_dev(&arg, nbr);
	printf("\nn_bytes = %d\n\n", arg.n_bytes);
}

void	putstr_tester(void)
{
	t_arg	arg;
	int		return_value;
	char	*str;

	arg.width = 10;
	arg.precision = 3;
	// arg.flags |= FLAG_MINUS;
	// arg.flags |= FLAG_ZERO;
	arg.flags |= FLAG_PREC;
	// arg.flags |= FLAG_WIDTH;
	arg.n_bytes = 0;

	printf("------Tests for ft_printf_putstr------\n");
	printf("for str = \"%s\", width = %d, and precision = %d\n", "test", arg.width, arg.precision);
	printf("The real printf:\n");
	return_value = printf("%*.*s", arg.width, arg.precision, "test");
	printf("\nreturn value = %d\n", return_value);
	ft_printf_str_dev(&arg, "test");
	printf("\nreturn value = %d\n", arg.n_bytes);

}

void	putchar_tester(void)
{
	t_arg	arg;
	
	arg.width = 5;
	arg.flags = FLAG_ZERO + FLAG_WIDTH + FLAG_MINUS;
	arg.flags = FLAG_ZERO + FLAG_WIDTH;
	arg.flags = FLAG_WIDTH;
	arg.flags = 0;
	arg.n_bytes = 0;

	ft_printf_char_dev(&arg, 'a');
	printf("\narg->n_bytes = %d\n", arg.n_bytes);
	printf("arg->width = %d\n", arg.width);
}

int main(void)
{
	// putchar_tester();
	// putstr_tester();
	putnbr_tester();
	// putnbr_u_tester();
	// puthex_tester();

	return (0);
}

const char *byte_to_binary (int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}
