#include <stdio.h>
#include <string.h>
int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	*str3, *str4, *str5, *str6, *str7, *str8, *str9, *str10;
	char	str1[100] = { 't', 'e', 's', 't', '\0'};
	char	str2[100] = { 't', 'e', 's', 't', '\0'};
	char	str11[100] = {'t', 'e', 's', 't', ':', 200, '\0'};
	char	str12[100] = {'t', 'e', 's', 't', ':', -5, '\0'};

	printf("s1 : %s\ns2 : %s\n", str1, str2);
	printf("What does strcmp have to say about it? : %d\n", strcmp(str1, str2));
	printf("What about your fct : %d\n\n", ft_strcmp(str1, str2));
	str3 = "patate1";
	str4 = "patate7";
	printf("s1 : %s\ns2 : %s\n", str3, str4);
	printf("What does strcmp have to say about it? : %d\n", strcmp(str3, str4));
	printf("What about your fct : %d\n\n", ft_strcmp(str3, str4));
	str5 = "patate8";
	str6 = "patate0";
	printf("s1 : %s\ns2 : %s\n", str5, str6);
	printf("What does strcmp have to say about it? : %d\n", strcmp(str5, str6));
	printf("What about your fct : %d\n\n", ft_strcmp(str5, str6));
	str7 = "patate123456";
	str8 = "patate";
	printf("s1 : %s\ns2 : %s\n", str7, str8);
	printf("What does strcmp have to say about it? : %d\n", strcmp(str7, str8));
	printf("What about your fct : %d\n\n", ft_strcmp(str7, str8));
	str9 = "patate";
	str10 = "patate%";
	printf("s1 : %s\ns2 : %s\n", str9, str10);
	printf("What does strcmp have to say about it? : %d\n", strcmp(str9, str10));
	printf("What about your fct : %d\n\n", ft_strcmp(str9, str10));
	printf("s1 : %s\ns2 : %s\n", str11, str12);
	printf("What does strncmp have to say about it? : %d\n", strcmp(str11, str12));
	printf("What about your fct : %d\n\n", ft_strcmp(str11, str12));
}
