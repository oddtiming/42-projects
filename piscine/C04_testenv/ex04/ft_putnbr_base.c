#include <unistd.h>
int		baseSize(char *base);
void	ft_putchar(char c);

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = baseSize(base);
	if (size < 2)
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(-2147483648 / size, base);
		ft_putchar(base[-2147483648 % size]);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-nbr, base);
	}
	else if (nbr >= 0)
	{
		if (nbr >= size)
			ft_putnbr_base(nbr / size, base);
		ft_putchar(base[nbr % size]);
	}
}

int	baseSize(char *base)
{
	int		index;
	char	compare;
	int		j;

	index = 0;
	while (base[index] != '\0')
	{
		compare = base[index];
		j = index + 1;
		if (base[index] == '+' || base[index] == '-' || base[index] < 32)
			return (0);
		while (base[j] != '\0')
		{
			if (compare == base[j])
				return (0);
			j++;
		}
		index++;
	}
	return (index);
}

void	ft_putchar(char c)
{
	write(1, &c, sizeof(c));
}
