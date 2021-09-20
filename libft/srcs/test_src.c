#include "../libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int	main(void)
{
	char	s1[50];
	int		fd = 1;

	strcpy(s1, "This is a test string");
	printf("For fd = %d && string = '%s'\nResult of ft_putstr_fd: \n", fd, s1);
	ft_putendl_fd(s1, fd);
	printf("\n");

}