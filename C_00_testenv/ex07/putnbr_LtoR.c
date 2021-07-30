#include <unistd.h>
void	printchar(char c);
int		orderDetermination(int i);

void	ft_putnbr(int nb)
{
	int	divider;
	int	firstDig;
	int	remainder;

	divider = orderDetermination(nb);
	firstDig = nb / divider;
	remainder = nb % divider;
	if (firstDig < 0)
	{
		printchar('-');
		firstDig = -1 * firstDig;
	}
	printchar(firstDig + '0');
	while (((nb / (divider / 10)) == 0) && (divider != 0))
	{
		printchar('0');
		divider = divider / 10;
	}
	if (remainder < 0)
		ft_putnbr(-1 * remainder);
	else if (remainder / 10 == 0)
		printchar(remainder + '0');
	else
		ft_putnbr(remainder);
}

int	orderDetermination(int i)
{
	int	divider;

	divider = 1;
	if (i >= 1000000000 || i <= -1000000000)
		return (1000000000);
	while (i / (10 * divider) != 0)
	{
		divider = 10 * divider;
	}
	return (divider);
}

void	printchar(char c)
{
	write(1, &c, 1);
}
