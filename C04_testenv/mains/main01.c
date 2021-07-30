#include <stdio.h>
#include <string.h>
void	ft_putstr(char *str);

int	main(void)
{
	char	*str1 = "test";
	char	*str2 = "patatepoil";
	char	*str3 = "";

	printf("printf str1: \n%s\nYour fct: \n", str1);
	ft_putstr(str1);
	printf("\n\nprintf str2: \n%s\nYour fct: \n", str2);
	ft_putstr(str2);
	printf("\n\nprintf str3: \n%s\nYour fct: \n", str3);
	ft_putstr(str3);
	printf("\n");
}
