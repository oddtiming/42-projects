#include <unistd.h>

void	printchar(char c);
void	printint(int i);

void	ft_print_comb2(void)
{
	int	i1;
	int	i2;

	i1 = 0;
	i2 = 0;
	while (i1 < 99)
	{
		i2 = i1;
		while (++i2 <= 99)
		{
			if (i1 != i2)
			{
				printint(i1);
				printchar(' ');
				printint(i2);
				if (i1 != 98)
				{
					printchar(' ');
					printchar(',');
				}
			}
		}
		i1++;
	}
}

void	printint(int i)
{
	char	a1;
	char	a2;

	a1 = (i / 10) + '0';
	a2 = (i % 10) + '0';
	printchar(a1);
	printchar(a2);
}

void	printchar(char c)
{
	write(1, &c, 1);
}
