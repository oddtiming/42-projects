#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int	get_magnitude(int n)
{
	int	magnitude;

	magnitude = 1;
	while (n >= 10)
	{
		magnitude *= 10;
		n /= 10;
	}
	return (magnitude);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		magnitude;
	char	nb;

	magnitude = get_magnitude(n);
	if (n < 0)
	{
		write(fd, "-", sizeof(char));
		if (n == INT_MIN)
		{
			write(fd, "2", sizeof(char));
			n = n % magnitude;
			magnitude /= 10;
		}
		n *= -1;
	}
	while (magnitude)
	{
		nb = n / magnitude + '0';
		write(fd, &nb, sizeof(char));
		n = n % magnitude;
		magnitude /= 10;
	}
}

int	main(void)
{
	int nb;
	int	fd;

	nb = 1235124;
	fd = 1;
	printf("For fd = %d && nb = %d, output is :\n", fd, nb);
	ft_putnbr_fd(nb, fd);
	printf("\n");
}
