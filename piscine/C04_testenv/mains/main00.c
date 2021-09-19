#include <stdio.h>
#include <string.h>
int	ft_strlen(char *str);

int	main(void)
{
	char	*str1 = "test";
	char	*str2 = "";

	printf("str1 : '%s'\nstrlen: %lu\nYour fct: %d\n\n", str1, strlen(str1), ft_strlen(str1));
	printf("str2 : '%s'\nstrlen: %lu\nYour fct: %d\n\n", str2, strlen(str2), ft_strlen(str2));
}
