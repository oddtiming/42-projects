void	ft_putchar(char c);

void	rush01(int x, int y)
{
	int	posX;
	int	posY;

	posX = 0;
	posY = 0;
	while (++posY <= y)
	{
		while (++posX <= x)
		{
			if (posX == 1 && posY == 1)
				ft_putchar('/');
			else if (posX == 1 && posY == y)
				ft_putchar('\\');
			else if ((posX == x) && (posY == 1))
				ft_putchar('\\');
			else if (posX == x && posY == y)
				ft_putchar('/');
			else if ((posX == 1 || posY ==1) || (posX == x || posY == y))
				ft_putchar('*');
			else
				ft_putchar(' ');
		}
		posX = 0;
		ft_putchar('\n');
	}
}
