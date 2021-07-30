#include <unistd.h>
void	printhex(unsigned char c);
int		isPrintable(char c);
void	printchar(char c);

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (isPrintable(str[i]))
			printchar(str[i]);
		else if (str[i] < 32)
		{
			printchar('\\');
			printhex((unsigned char)str[i]);
		}
		i++;
	}
}

void	printhex(unsigned char c)
{
	char	*hexBase;

	hexBase = "0123456789abcdef";
	write(1, &hexBase[c / 16], 1);
	write(1, &hexBase[c % 16], 1);
}

int	isPrintable(char c)
{
	if (c < 32)
		return (0);
	else
		return (1);
}

void	printchar(char c)
{
	write(1, &c, sizeof(c));
}
