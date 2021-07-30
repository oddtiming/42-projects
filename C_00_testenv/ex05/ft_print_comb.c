#include <unistd.h>
void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int	dig1;
	int	dig2;
	int	dig3;

	dig1 = -1;
	while (++dig1 <= 7)
	{
		dig2 = dig1;
		while (++dig2 <= 8)
		{
			dig3 = dig2;
			while (++dig3 <= 9)
			{
				ft_putchar(dig1 + '0');
				ft_putchar(dig2 + '0');
				ft_putchar(dig3 + '0');
				if (dig1 != 7)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
