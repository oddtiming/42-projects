#include "ft_printf_bonus.h"

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

//returns (magnitude+1), b/c 0<=numbers<=9 still need one char
int	get_magnitude(int n)
{
	int	magnitude;

	magnitude = 0;
	while (n)
	{
		magnitude *= 10;
		n /= 10;
	}
	return (magnitude + 1);
}

int	get_magnitude_unsigned(unsigned int n)
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

int	ft_putnbr_n_ret(int nbr, int prec)
{
	int		magnitude;
	int		i;
	int		temp_nbr;
	long	n_to_long;

	magnitude = get_magnitude(nbr);
	i = 0;
	n_to_long = nbr;
	if (n_to_long < 0)
	{
		i += write(1, "-", sizeof(char));
		n_to_long *= -1;
	}
	//NOTE: There may be some issues with using a size_t with negative numbers?
	temp_nbr = ft_log_calc_size_t(n_to_long, 10) + i;
	//NOTE: The previous temp_nbr setting is to account for '-' characters being printed,
	//but there seems to be some issues with '+' and ' ' flags.
	while (prec-- >= temp_nbr)
	//>= used here for cases where there is an over or undershoot.
		i += write(1, "0", sizeof(char));
	while (magnitude)
	{
		temp_nbr = n_to_long / magnitude + '0';
		i += write(1, &temp_nbr, sizeof(char));
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
