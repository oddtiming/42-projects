#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	int	size = 5;
    char *strings[5] = {"This", "should", "form", "a", "sentence"};
    int i = 0;
	char *sep = " || ";
	
	for(i = 0; i < size; i++)
        printf("String #%d (length: %lu) = '%s'\n", i, strlen(strings[i]),strings[i]);
	printf("The separator is '%s'\n", sep);
	printf("Resulting string:\n'%s'\n(length: %lu)\n\n", ft_strjoin(size, strings,  sep), strlen(ft_strjoin(size, strings, sep)));


	size = 3;
	printf("For size = %d:\n", size);
	printf("Resulting string:\n'%s'\n(length: %lu)\n\n", ft_strjoin(size, strings,  sep), strlen(ft_strjoin(size, strings, sep)));
	size = 1;
	printf("For size = %d:\n", size);
	printf("Resulting string:\n'%s'\n(length: %lu)\n\n", ft_strjoin(size, strings,  sep), strlen(ft_strjoin(size, strings, sep)));
	size = 0;
	printf("For size = %d:\n", size);
	printf("Resulting string:\n'%s'\n(length: %lu)\n", ft_strjoin(size, strings,  sep), strlen(ft_strjoin(size, strings, sep)));
}
