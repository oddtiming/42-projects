#include "libft.h"

void	ft_writehex(int i, char c)
{
	char	*hexBase;

	if (c == 'x')
		hexBase = "0123456789abcdef";
	else
		hexBase = "0123456789ABCDEF";
	if (i > 15)
		ft_writehex(i / 16, c);
	write(1, &hexBase[i % 16], 1);
}

void	ft_writehex_long(long i)
{
	char	*hexBase;

	hexBase = "0123456789abcdef";
	if (i > 15)
		ft_writehex_long(i / 16);
	write(1, &hexBase[i % 16], 1);
}

static long	power_calc(int base, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (base * power_calc(base, power - 1));
}

static int	get_a_len(long n)
{
	int	a_len;

	a_len = 0;
	if (!n)
		return (1);
	if (n < 0)
		a_len++;
	while (n)
	{
		n /= 16;
		a_len++;
	}
	return (a_len);
}

char	*ft_hextoa(long n)
{
	int		a_len;
	char	*n_to_a;
	long	i;
	char	*hex_base;

	hex_base = "0123456789abcdef";
	i = 0;
	a_len = get_a_len(n);
	n_to_a = malloc(a_len + 1);
	if (!n_to_a)
		return (NULL);
	if (n < 0)
	{
		n_to_a[i++] = '-';
		n *= -1;
		a_len--;
	}
	while (a_len--)
	{
		n_to_a[i++] = hex_base[n / power_calc(16, a_len)];
		n = n % power_calc(16, a_len);
	}
	n_to_a[i] = 0;
	return (n_to_a);
}
