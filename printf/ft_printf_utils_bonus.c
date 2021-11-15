#include "ft_printf_bonus.h"

//Sets everything to zero on first passage, not sure if necessary or if
//I could have declared a static struct in ft_printf
void	printf_struct_init(t_arg *arg, char const *format)
{
	arg->n_bytes = 0;
	arg->index = 0;
	arg->precision = 0;
	arg->width = 0;
	arg->var_type = 0;
	arg->flags = 0;
	arg->fmt = ft_strdup(format);
}

//Reset the conversion-specific values of the
void	printf_struct_reset(t_arg *arg)
{
	arg->precision = 0;
	arg->width = 0;
	arg->var_type = 0;
	arg->flags = 0;
}

//Prints a number of length 'prec', and returns the amount of chars printed
int	ft_putnbr_unsigned_n_ret(unsigned int n, int prec)
{
	int		magnitude;
	int		i;
	int		nbr_size;
	char	nb_to_char;

	magnitude = get_magnitude_unsigned(n);
	i = 0;
	nbr_size = ft_log_calc_size_t(n, 10);
	while (prec-- > nbr_size)
		i += write(1, "0", 1);
	while (magnitude)
	{
		nb_to_char = n / magnitude + '0';
		i += write(1, &nb_to_char, 1);
		n = n % magnitude;
		magnitude /= 10;
	}
	return (i);
}

//Prints 'prec' chars from a string, and returns the amount of chars printed
int	ft_putstr_n_ret(const char *s, int prec)
{
	int	i;

	i = 0;
	while (s[i] && i < prec)
		i += write(1, &s[i], 1);
	return (i);
}

//Recusrive putnbr function for hexadecimals specific for ft_printf, since
//hex_base is determined by the var_type of the printf conversion
void	ft_puthex_size_t(t_arg *arg, size_t i)
{
	char	*hex_base;

	if (is_set(arg->var_type, "xp"))
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	if (i > 15)
		ft_puthex_size_t(arg, i / 16);
	write(1, &hex_base[i % 16], 1);
	arg->n_bytes += 1;
}
