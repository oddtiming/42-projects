void	ft_putchar(char c);
int		posChar(int posX, int posY, int maxX, int maxY);

void	rush04(int x, int y)
{
	int	pX;
	int	pY;

	pX = 0;
	pY = 0;
	while (++pY <= y)
	{
		while (++pX <= x)
		{
			if (posChar(pX, pY, x, y) == 0 || posChar(pX, pY, x, y) == 3)
				ft_putchar('A');
			else if (posChar(pX, pY, x, y) == 1 || posChar(pX, pY, x, y) == 2)
				ft_putchar('C');
			else if (posChar(pX, pY, x, y) == 4 || posChar(pX, pY, x, y) == 5)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		pX = 0;
		ft_putchar('\n');
	}
}

int	posChar(posX, posY, maxX, maxY)
{
	if ((posX == 1 || posX == maxX) || (posY == 1 || posY == maxY))
	{
		if (posX == 1 && posY == 1)
			return (0);
		else if (posX == maxX && posY == 1)
			return (1);
		else if (posX == 1 && posY == maxY)
			return (2);
		else if ((posX == maxX && maxX != 1) && (posY == maxY && maxY != 1))
			return (3);
		else if (posY == 1 ||posY == maxY)
			return (4);
		else
			return (5);
	}
	else
		return (6);
}
// 0 is top left corner
// 1 is top right corner
// 2 is bottom left corner
// 3 is bottom right corner
// 4 is non-corner horizontal edges
// 5 is non-corner vertical edges
// 6 is the body
