#include "ft_printf.h"

char	*c_to_s(int c)
{
	char	*str;

	str = malloc(2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

static int	power_calc(int base, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (base * power_calc(base, power - 1));
}

static int	get_a_len(unsigned int n, int base)
{
	int	a_len;

	a_len = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= base;
		a_len++;
	}
	return (a_len);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int				a_len;
	char			*n_to_a;
	long			i;

	i = 0;
	a_len = get_a_len(n, 10);
	n_to_a = malloc(a_len + 1);
	if (!n_to_a)
		return (NULL);
	while (a_len--)
	{
		n_to_a[i++] = (n / power_calc(10, a_len)) + '0';
		n = n % power_calc(10, a_len);
	}
	n_to_a[i] = 0;
	return (n_to_a);
}

char	*ft_hextoa_int(unsigned int n, char c)
{
	int		a_len;
	char	*n_to_a;
	int		i;
	char	*hex_base;

	if (c == 'X')
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	i = 0;
	a_len = get_a_len(n, 16);
	n_to_a = malloc(a_len + 1);
	if (!n_to_a)
		return (NULL);
	while (a_len--)
	{
		n_to_a[i++] = hex_base[n / power_calc(16, a_len)];
		n = n % power_calc(16, a_len);
	}
	n_to_a[i] = 0;
	return (n_to_a);
}

char	*ft_strjoin_dbfree(char *s1, char *s2)
{
	size_t	tot_len;
	char	*s_joined;
	int		i;

	i = 0;
	tot_len = strlen_c(s1, 0) + strlen_c((char *)s2, 0) + 1;
	s_joined = malloc(tot_len);
	if (!s_joined)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			*s_joined++ = s1[i++];
		free (s1);
	}
	i = 0;
	if (s2)
	{
		while (s2[i])
			*s_joined++ = s2[i++];
		free (s2);
	}
	*s_joined++ = 0;
	return (s_joined - tot_len);
}
