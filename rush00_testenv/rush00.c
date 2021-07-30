void	ft_putchar(char c);

void	rush00(int x, int y)
{
	int	posX;
	int	posY;

	posY = 0;
	while (++posY <= y)
	{
		posX = 0;
		while (++posX <= x)
		{
			if ((posY == 1 || posY == y) && (posX == 1 || posX == x))
				ft_putchar('o');
			else if (posY == 1 ||posY == y)
				ft_putchar('-');
			else if (posX == 1 || posX == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
