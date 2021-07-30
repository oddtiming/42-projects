#include <unistd.h>
void	printchar(char c);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		printchar('8');
	}
	else if (nb < 0)
	{
		printchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	if (nb >= 0)
		printchar(nb % 10 + '0');
}

void	printchar(char c)
{
	write(1, &c, sizeof(c));
}
