#include <stdio.h>
#include <string.h>
unsigned int	ft_strlcat(char *s1, char *s2, unsigned int size);

int	main(void)
{
	char	*str2, *str4;
	char str1[100] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'm', 'i', 's', 's', 'i', 'n', 'g', '\0'};
	char str3[100] = {'L', 'e', 't', '\'', 's', ' ', 's', 'e', 'e', ' ', 'i', 'f', '\0'};
	
	int i = 5;
	str2 = " this part";
	printf("\ns1 : '%s'\ns2 : '%s'\n, n = %d\n", str1, str2, i);
	printf("Here's what strlcat does: '%lu'\nIs it null terminated? :", strlcat(str1, str2, strlen(str1) + i));
	if (str1[strlen(str1) + i] == '\0')
		printf(" Fok yaaaah\n");
	else
		printf(" Fok nooooo :((((\n");
	printf("New string : %s\n", str1);
	str4 = " yours work...";
	printf("\ns1 : '%s'\ns2 : '%s'\nn = %d\n", str3, str4, i);
	printf("Is yours as baller? : '%u'\nIs it null terminated? :", ft_strlcat(str3, str4, strlen(str3) + i));
	if (str1[strlen(str3) + i] == '\0')
		printf(" Fok yaaaah\n");
	else
		printf(" Fok nooooo :((((\n");
	printf("New string : %s\n", str3);
	return (0);
}
