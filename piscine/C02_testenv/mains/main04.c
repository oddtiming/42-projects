#include <stdio.h>
int	ft_str_is_lowercase(char *str);

int	main(void)
{
	char	*str1;
	char	*str2;
	char	empty[1];

	str1 = "fdshjahjfsadjhkfdsjkhgafdsjhkgf";
	str2 = "What !7 b3 what i7 d0!?";
	empty[0] = '\0';
	printf("Does this contain only alphabetical characters? : %s\n", str1);
	if (ft_str_is_lowercase(str1))
		printf("Yeppers\n");
	else
		printf("Nopers\n");
	printf("Does this contain only alphabetical characters? : %s\n", str2);
	if (ft_str_is_lowercase(str2))
		printf("Yeppers\n");
	else
		printf("Nopers\n");
	printf("Does this contain only alphabetical characters? : %s\n", empty);
	if (ft_str_is_lowercase(empty))
		printf("Yeppers\n");
	else
		printf("Nopers\n");
}
