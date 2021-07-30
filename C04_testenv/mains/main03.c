#include <stdio.h>
int ft_atoi(char *src);

int	main(void)
{
	char *str1 = "   -+-+---1234 ";
	char *str2 = " -+-+000248 22";
	char *str3 = "-2147483648 ";
	char str4[8] = {47, ':', '7', 't', 'e', 's', 't', '\0'};

	printf("str1 = '%s'\nYour function returns: %d\n\n", str1, ft_atoi(str1));
	printf("str2 = '%s'\nYour function returns: %d\n\n", str2, ft_atoi(str2));
	printf("str3 = '%s'\nYour function returns: %d\n\n", str3, ft_atoi(str3));
	printf("str4 = '%s'\nYour function returns: %d\n", str4, ft_atoi(str4));
}
