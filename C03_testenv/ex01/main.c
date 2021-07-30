#include <stdio.h>
#include <string.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char	*str1, *str2, *str3, *str4, *str5, *str6;
	char	str7[100] = {'t', 'e', 's', 't', ':', -55, '\0'};
	char	str8[100] = {'t', 'e', 's', 't', ':', '\0'};
	int		n;

	n = 4;
	str1 = "pouetT";
	str2 = "pouett";
	printf("\ns1 : %s\ns2 : %s\nn = %d\n", str1, str2, n);
	printf("What does strncmp have to say about it? : %d\n", strncmp(str1, str2, n));
	printf("What about your fct : %d\n\n", ft_strncmp(str1, str2, n));
	n = 6;
	printf("Now for n = %d\n", n);
	printf("What does strncmp have to say about it? : %d\n", strncmp(str1, str2, n));
	printf("What about your fct : %d\n\n", ft_strncmp(str1, str2, n));
	str3 = "patate123456";
	str4 = "patate";
	n = 7;
	printf("s1 : %s\ns2 : %s\nn= %d\n", str3, str4, n);
	printf("What does strncmp have to say about it? : %d\n", strncmp(str3, str4, n));
	printf("What about your fct : %d\n\n", ft_strncmp(str3, str4, n));
	str5 = "patate";
	str6 = "patate$";
	n = 6;
	printf("s1 : %s\ns2 : %s\nn = %d\n", str5, str6, n);
	printf("What does strncmp have to say about it? : %d\n", strncmp(str5, str6, n));
	printf("What about your fct : %d\n\n", ft_strncmp(str5, str6, n));
	printf("s1 : %s\ns2 : %s\nn = %d\n", str7, str8, n);
	printf("What does strncmp have to say about it? : %d\n", strncmp(str7, str8, n));
	printf("What about your fct : %d\n", ft_strncmp(str7, str8, n));
}
