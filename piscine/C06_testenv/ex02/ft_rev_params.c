#include <unistd.h>
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int	i;

	i = argc;
	while (--i > 0)
		ft_putstr(argv[i]);
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
