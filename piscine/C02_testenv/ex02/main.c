#include <stdio.h>
int	ft_str_is_alpha(char *str);

int	main(void)
{
	char	*alphanum;
	char	*nonalpha;
	char	empty[10];

	alphanum = "WhatItBeWhatItDo";
	nonalpha = "What !7 b3 what i7 d0!?";
	empty[0] = '\0';
	printf("Does this contain only alphabetical characters? : %s\n", alphanum);
	if (ft_str_is_alpha(alphanum))
		printf("Yeppers\n");
	else
		printf("Nopers\n");
	printf("Does this contain only alphabetical characters? : %s\n", nonalpha);
	if (ft_str_is_alpha(nonalpha))
		printf("Yeppers\n");
	else
		printf("Nopers\n");
	printf("Does this contain only alphabetical characters? : %s\n", empty);
	if (ft_str_is_alpha(empty))
		printf("Yeppers\n");
	else
		printf("Nopers\n");
}
