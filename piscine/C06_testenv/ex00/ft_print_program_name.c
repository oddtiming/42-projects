#include <unistd.h>
void	ft_putstr(char *str);
void	printchar(char c);

int	main(int argc, char **argv)
{
	ft_putstr(argv[0]);
	write(1, "\n", 1);
	argc = 1;
	return (0);
}

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
