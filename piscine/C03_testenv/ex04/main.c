#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	str1[100] = "test123";
	char	str2[100] = "testpoil123";
	char	str3[100] = "test12test123";
	char	str4[100] = "lolfthat";
	char	needle[100]	= "123";
	printf("\ns1: '%s'\ns2: '%s'\ns3: '%s'\ns4: '%s'\nneedle: %s\n\n", str1, str2, str3, str4, needle);
	printf("Result of strstr on test1: '%p'\nResult of yout fct on test1: '%p'\n", strstr(str1, needle), ft_strstr(str1, needle));
	printf("Result of strsr on test1: '%s'\nResult of yout fct on test1: '%s'\n\n", strstr(str1, needle), ft_strstr(str1, needle));
	printf("Result of strstr on test2: '%p'\nResult of yout fct on test2: '%p'\n", strstr(str2, needle), ft_strstr(str2, needle));
	printf("Result of strstr on test2: '%s'\nResult of yout fct on test2: '%s'\n\n", strstr(str2, needle), ft_strstr(str2, needle));
	printf("Result of strstr on test3: '%p'\nResult of yout fct on test3: '%p'\n", strstr(str3, needle), ft_strstr(str3, needle));
	printf("Result of strstr on test3: '%s'\nResult of yout fct on test3: '%s'\n\n", strstr(str3, needle), ft_strstr(str3, needle));
	printf("Result of strstr on test4: '%p'\nResult of yout fct on test4: '%p'\n", strstr(str4, needle), ft_strstr(str4, needle));
	printf("Result of strstr on test4: '%s'\nResult of yout fct on test4: '%s'\n\n", strstr(str4, needle), ft_strstr(str4, needle));
	printf("What if needle is empty?\n");
	char	needleEmpty[10] = {'\0'};
	printf("Address: %p\nValue: %s\n", ft_strstr(str4, needleEmpty), ft_strstr(str4, needleEmpty));
	printf("Address for strstr: %p\nValue for strstr: %s\n", strstr(str4, needleEmpty), strstr(str4, needleEmpty));
	return (0);
}
