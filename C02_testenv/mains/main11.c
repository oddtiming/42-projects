#include <stdio.h>
#include <string.h>
void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	str1[] = {'t', 'E', '\n', 't', ',', 17, 22, 26, 'e', 'l', ' ', 'a', 'L', 'l', '+', 'b', 'r', 'a', 'n', '?', 'v', 'e', 's', 't', -3, ' ', '3', 'r', 'd', ' ', 'b', 'i', '-', 'p', 'o', 'l', '\0'};
	
	printf("String to be modified:\n%s, length = %lu\n", str1, strlen(str1));
	printf("Modified: \n");
	ft_putstr_non_printable(str1);
	return (0);
}
