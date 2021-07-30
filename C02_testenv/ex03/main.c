#include <stdio.h>
int	ft_str_is_numeric(char *str);

int	main(void)
{
	char	*num;
	char	*nonnum;
	char	empty[1];

	num = "12321798053409234980532";
	nonnum = "What !7 b3 what i7 d0!?";
	empty[0] = '\0';
	printf("Does this contain only alphabetical characters? : %s\n", num);
	if (ft_str_is_numeric(num))
		printf("Yeppers\n");
	else
		printf("Nopers\n");
	printf("Does this contain only alphabetical characters? : %s\n", nonnum);
	if (ft_str_is_numeric(nonnum))
		printf("Yeppers\n");
	else
		printf("Nopers\n");
	printf("Does this contain only alphabetical characters? : %s\n", empty);
	if (ft_str_is_numeric(empty))
		printf("Yeppers\n");
	else
		printf("Nopers\n");
}
