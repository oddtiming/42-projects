#include <stdio.h>
#include <string.h>
char	*ft_strupcase(char *str);

int	main(void)
{
	char	str1[] = {'t', 'e', 's', 't', '4', '2', '\0'};
	char	str2[] = {'T', 'E', 'S', 'T', '4', '2', '\0'};
	char	str3[] = {'T', 'e', 'S', 't', '@', '[', '{', '4', '2', '\0'};

	printf("String to be modified: %s, length = %lu\n", str1, strlen(str1));
	printf("Modified: %s\n", ft_strupcase(str1));
	printf("String to be modified: %s\n", str2);
	printf("Modified: %s\n", ft_strupcase(str2));
	printf("String to be modified: %s\n", str3);
	printf("Modified: %s\n", ft_strupcase(str3));
	return (0);
}
