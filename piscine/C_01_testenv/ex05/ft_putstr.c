#include <unistd.h>

void	printchar(char c)
{
	write(1, &c, sizeof(c));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		printchar(str[i]);
		i++;
	}
}
