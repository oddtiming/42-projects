#include "ft_printf.h"

void	printf_struct_init(t_arg *holder, char const *format)
{
	holder->n_bytes = 0;
	holder->index = 0;
	holder->precision = 0;
	holder->width = 0;
	holder->var_type = 0;
	holder->flags = 0;
	holder->format = ft_strdup(format);
}

int	ft_putchar_ret(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_ret(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

static int	get_magnitude(int n)
{
	int	magnitude;

	magnitude = 1;
	if (n >= 0)
	{	
		while (n >= 10)
		{
			magnitude *= 10;
			n /= 10;
		}
	}
	else if (n < 0)
	{	
		while (n <= -10)
		{
			magnitude *= 10;
			n /= 10;
		}
	}
	return (magnitude);
}

static int	get_magnitude_unsigned(unsigned int n)
{
	int	magnitude;

	magnitude = 1;
	while (n >= 10)
	{
		magnitude *= 10;
		n /= 10;
	}
	return (magnitude);
}

static long	get_magnitude_hex(unsigned long n)
{
	long	magnitude;

	magnitude = 1;
	while (n >= 16)
	{
		magnitude *= 16;
		n /= 16;
	}
	return (magnitude);
}

int	ft_putnbr_ret(int n)
{
	int		magnitude;
	int		i;
	char	nb;
	long	n_to_long;

	magnitude = get_magnitude(n);
	i = 0;
	n_to_long = n;
	if (n_to_long < 0)
	{
		write(1, "-", sizeof(char));
		i++;
		n_to_long *= -1;
	}
	while (magnitude)
	{
		nb = n_to_long / magnitude + '0';
		write(1, &nb, sizeof(char));
		i++;
		n_to_long = n_to_long % magnitude;
		magnitude /= 10;
	}
	return (i);
}

int	ft_putnbr_unsigned_ret(unsigned int n)
{
	int		magnitude;
	int		i;
	char	nb;

	magnitude = get_magnitude_unsigned(n);
	i = 0;
	while (magnitude)
	{
		nb = n / magnitude + '0';
		write(1, &nb, sizeof(char));
		i++;
		n = n % magnitude;
		magnitude /= 10;
	}
	return (i);
}

int	ft_putaddress_ret(unsigned long address)
{
	int		i;
	long	magnitude;
	char	*hex_base;

	i = 0;
	hex_base = "0123456789abcdef";
	magnitude = get_magnitude_hex(address);
	printf("magnitude = %lu\n", magnitude);
	printf("address = %lu\n", address);
	write(1, "0x", 2);
	i += 2;
	while (magnitude)
	{
		write(1, &hex_base[address / magnitude], sizeof(char));
		i++;
		address = address % magnitude;
		magnitude /= 10;
	}
	return (i);
}

void	ft_puthex_long_long(long long i, t_arg *holder)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (i > 15)
		ft_puthex_long_long(i / 16, holder);
	write(1, &hex_base[i % 16], 1);
	holder->n_bytes += 1;
}

void	ft_puthex_long(long i, t_arg *holder)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (i > 15)
		ft_puthex_long(i / 16, holder);
	write(1, &hex_base[i % 16], 1);
	holder->n_bytes += 1;
}

void	ft_puthex_size_t(size_t i, t_arg *holder)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (i > 15)
		ft_puthex_size_t(i / 16, holder);
	write(1, &hex_base[i % 16], 1);
	holder->n_bytes += 1;
}

void	ft_puthex_int(unsigned int i, t_arg *holder)
{
	char	*hex_base;

	if (holder->var_type == 'x')
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	if (i > 15)
		ft_puthex_int(i / 16, holder);
	write(1, &hex_base[i % 16], 1);
	holder->n_bytes += 1;
}
