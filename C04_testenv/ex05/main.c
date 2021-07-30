#include <stdio.h>
#include <string.h>
int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	char *str1 = "0123456789";
	char *str2 = "poneyvif";
	char *str3 = "0123456789abcdef";
	char *str4 = "0123456789abcdef";
	char *str5 = " +---+1234 4";

	printf("str = '%s'\nbase = '%s'\nYour function returns: %d\n\n", str5, str1, ft_atoi_base(str5, str1));
	char *str6 = "oevf";
	printf("str = '%s'\nbase = '%s'\nYour function returns: %d\n\n", str6, str2, ft_atoi_base(str6, str2));
	char *str7 = "abeef";
	printf("str = '%s'\nbase = '%s'\nYour function returns: %d\n\n", str7, str3, ft_atoi_base(str7, str3));
	char *str8 = "ab908";
	printf("str = '%s'\nbase = '%s'\nYour function returns: %d\n\n", str8, str4, ft_atoi_base(str8, str4));
	printf("str = '%s'\nbase = '%s'\nYour function returns: %d\n\n", str6, str4, ft_atoi_base(str6, str4));
}
