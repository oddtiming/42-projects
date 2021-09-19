#include <stdio.h>
#include <string.h>
unsigned int	ft_strlcat(char *s1, char *s2, unsigned int size);

int	main(void)
{
	unsigned int size;
	char	*str2, *str4;
	char str1[100] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'm', 'i', 's', 's', 'i', 'n', 'g', '\0'};
	char str3[100] = {'L', 'e', 't', '\'', 's', ' ', 's', 'e', 'e', ' ', 'i', 'f', '\0'};
	
	size = 18;
	str2 = " this part";
	printf("\ns1 : '%s'\ns2 : '%s'\nsize = %d\n", str1, str2, size);
	printf("Here's what strcat gives: '%lu'\n", strlcat(str1, str2, size));
	printf("Here's what strcat does: '%s'\nIs it null terminated? :", str1);
	if (str1[strlen(str1) + strlen(str2)] == '\0')
		printf(" Fok yaaaah\n\n");
	else
		printf(" Fok nooooo :((((\n\n");
	str4 = " yours work...";
	printf("\ns1 : '%s'\ns2 : '%s'\nsize = %d\n", str3, str4, size);
	printf("Here's what yours gives : '%u'\n", ft_strlcat(str3, str4, size));
	printf("Here's what yours does: '%s'\nIs it null terminated? :", str3);
	if (str1[strlen(str3) + strlen(str4)] == '\0')
		printf(" Fok yaaaah\n");
	else
		printf(" Fok nooooo :((((\n");
	size = 5;
	str2 = " this part";
	printf("\ns1 : '%s'\ns2 : '%s'\nsize = %d\n", str1, str2, size);
	printf("Here's what strcat gives: '%lu'\n", strlcat(str1, str2, size));
	printf("Here's what strcat does: '%s'\nIs it null terminated? :", str1);
	if (str1[strlen(str1) + size] == '\0')
		printf(" Fok yaaaah, which means fok nooooo :(((((\n\n");
	else
		printf(" Fok nooooo, which means fok yaaaaaah :)))\n\n");
	str4 = " yours work...";
	printf("\ns1 : '%s'\ns2 : '%s'\nsize = %d\n", str3, str4, size);
	printf("Here's what yours gives : '%u'\n", ft_strlcat(str3, str4, size));
	printf("Here's what yours does: '%s'\nIs it null terminated? :", str3);
	if (str1[strlen(str3) + size] == '\0')
		printf(" Fok yaaaah, which means fok nooooo :(((((\n\n");
	else
		printf(" Fok nooooo, which means fok yaaaaaah :)))\n\n");
	return (0);
}
