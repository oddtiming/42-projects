#include <unistd.h>
void	ft_putstr(char *str);
int		ft_strcmp(char *str1, char *str2);

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	buffer = 0;
	while (i++ < argc)
	{
		j = 0;
		while (j++ < argc - i -1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				buffer = argv[j + 1];
				argv[j + 1] = argv[j];
				argv[j] = buffer;
			}
		}
	}
	i = 0;
	while (++i < argc)
		ft_putstr(argv[i]);
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str2[i] != 0)
		i++;
	return (str1[i] - str2[i]);
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
