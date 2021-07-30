void	ft_putchar(char c);

void	rush04(int x, int y)
{
	int	posX;
	int	posY;

	posX = 0;
	posY = 0;
	while (++posY <= y)
	{
		while (++posX <= x)
		{
			if ((posY == 1 && posX == 1) || (posX == x != 1 && posY == y != 1))
				ft_putchar('A');
			else if ((posX == x && posY == 1) || (posX == 1 && posY == y))
				ft_putchar('C');
			else if ((posX == 1 ||posY ==1) || (posX == x || posY == y))
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		posX = 0;
		ft_putchar('\n');
	}
}
