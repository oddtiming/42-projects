#include <stdio.h>
#include <string.h>
char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	str1[] = {'t', 'E', 's', 't', ',', 'b', 'a', 'g', 'e', 'l', ' ', 'a', 'L', 'l', '+', 'b', 'r', 'a', 'n', '?', 'v', 'e', 's', 't', 'e', ' ', '3', 'r', 'd', ' ', 'b', 'i', '-', 'p', 'o', 'l', '\0'};

	printf("String to be modified:\n%s, length = %lu\n", str1, strlen(str1));
	printf("Modified: \n%s\n", ft_strcapitalize(str1));
	return (0);
}
