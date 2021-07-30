#include <stdio.h>
#include <unistd.h>
void	printhex(char	c);

int	main(void)
{
	char	c;

	c = 'j';
	printhex(c);
	return (0);
}

void	printhex(char c)
{
	char	firstHex;
	char	secondHex;

	firstHex = (c / 16) + '0';
	secondHex = c % 16;
	if (secondHex > 9)
		secondHex += 'a' - 10;
	else
		secondHex += '0';
	write(1, &firstHex, 1);
	write(1, &secondHex, 1);
	write(1, "\n", 1);
}
