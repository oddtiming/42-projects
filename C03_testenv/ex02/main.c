#include <stdio.h>
#include <string.h>
char	*ft_strcat(char *s1, char *s2);

int	main(void)
{
	char	*str2, *str4;
	char str1[100] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'm', 'i', 's', 's', 'i', 'n', 'g', '\0'};
	char str3[100] = {'L', 'e', 't', '\'', 's', ' ', 's', 'e', 'e', ' ', 'i', 'f', '\0'};
	
	str2 = " this part";
	printf("\ns1 : '%s'\ns2 : '%s'\n", str1, str2);
	printf("Here's what strcat does: '%s'\nIs it null terminated? :", strcat(str1, str2));
	if (str1[strlen(str1) + strlen(str2)] == '\0')
		printf(" Fok yaaaah\n\n");
	else
		printf(" Fok nooooo :((((\n\n");
	str4 = " yours work...";
	printf("\ns1 : '%s'\ns2 : '%s'\n", str3, str4);
	printf("Is yours as baller? : '%s'\nIs it null terminated? :", ft_strcat(str3, str4));
	if (str1[strlen(str3) + strlen(str4)] == '\0')
		printf(" Fok yaaaah\n");
	else
		printf(" Fok nooooo :((((\n");
	return (0);
}
