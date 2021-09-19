#include <stdio.h>
#include <string.h>
char	*ft_strncat(char *s1, char *s2, unsigned int nb);

int	main(void)
{
	unsigned int nb;
	char	*str2, *str4;
	char str1[100] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'm', 'i', 's', 's', 'i', 'n', 'g', '\0'};
	char str3[100] = {'L', 'e', 't', '\'', 's', ' ', 's', 'e', 'e', ' ', 'i', 'f', '\0'};
	
	nb = 5;
	str2 = " this part";
	printf("\ns1 : '%s'\ns2 : '%s'\nnb = %d\n", str1, str2, nb);
	printf("Here's what strcat does: '%s'\nIs it null terminated? :", strncat(str1, str2, nb));
	if (str1[strlen(str1) + strlen(str2)] == '\0')
		printf(" Fok yaaaah\n\n");
	else
		printf(" Fok nooooo :((((\n\n");
	str4 = " yours work...";
	printf("\ns1 : '%s'\ns2 : '%s'\nnb = %d\n", str3, str4, nb);
	printf("Is yours as baller? : '%s'\nIs it null terminated? :", ft_strncat(str3, str4, nb));
	if (str1[strlen(str3) + strlen(str4)] == '\0')
		printf(" Fok yaaaah\n");
	else
		printf(" Fok nooooo :((((\n");
	nb = 18;
	str2 = " this part";
	printf("\ns1 : '%s'\ns2 : '%s'\nnb = %d\n", str1, str2, nb);
	printf("Here's what strcat does: '%s'\nIs it null terminated? :", strncat(str1, str2, nb));
	if (str1[strlen(str1) + strlen(str2)] == '\0')
		printf(" Fok yaaaah\n\n");
	else
		printf(" Fok nooooo :((((\n\n");
	str4 = " yours work...";
	printf("\ns1 : '%s'\ns2 : '%s'\nnb = %d\n", str3, str4, nb);
	printf("Is yours as baller? : '%s'\nIs it null terminated? :", ft_strncat(str3, str4, nb));
	if (str1[strlen(str3) + strlen(str4)] == '\0')
		printf(" Fok yaaaah\n");
	else
		printf(" Fok nooooo :((((\n");
	return (0);
}
