#include <unistd.h>

void	ft_putchar(char c);

void	rush04(int a, int b)
{
	int	posX;
	int	posY;

	posX = 1;
	posY = 1;
	while (posY <= b)
	{
		posX = 1;
		while (posX <= a)
		{
			if ((posX == 1 && posY == 1) || (posX == a && posY == b))
				ft_putchar('A');
			else if ((posX == a && posY == 1) || (posX == 1 && posY == b))
				ft_putchar('C');
			else if ((posY == (b || 1)) || (posX == (1 || a)))
				ft_putchar('B');
			else
				ft_putchar('x');
			posX++;
		}
		ft_putchar('\n');
		posY++;
	}
}
