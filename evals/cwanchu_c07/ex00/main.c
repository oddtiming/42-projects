#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char	*ft_strdup(char *src);

int	main(void)
{
	char *src = "test patate poil";

	printf("This is the src: '%s'\n", src);
	printf("This is the duplicate from strdup : '%s'\n", strdup(src));
	printf("This is the duplicate from your fct : '%s'\n", ft_strdup(src));
	printf("Is it null terminated ?\n");
	int size_dup = strlen(src);
	char *dup = (char *)malloc(size_dup + 1);
	dup = ft_strdup(src);
	if (dup[size_dup] == 0)
		printf("OOOOOOH, yes it is, good job bb <3<3<3\n");
	else
		printf("OH NOES you done fucked up, boi </3\n");
	
	char *src2 = "";

	printf("This is the src: '%s'\n", src2);
	printf("This is the duplicate from strdup : '%s'\n", strdup(src2));
	printf("This is the duplicate from your fct : '%s'\n", ft_strdup(src2));
	printf("Is it null terminated ?\n");
	size_dup = strlen(src2);
	free (dup);
	dup = (char *)malloc(size_dup + 1);
	dup = ft_strdup(src2);
	if (dup[size_dup] == 0)
		printf("OOOOOOH, yes it is, good job bb <3<3<3\n");
	else
		printf("OH NOES you done fucked up, boi </3\n");
}
