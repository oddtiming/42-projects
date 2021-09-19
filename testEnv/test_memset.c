#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[50];
   	strcpy (str1, "This is a test sentence");
	printf("Initial string: '%s'\n", str1);
	puts(str1);

	memset(str1, '*', 5);
	puts (str1);
}
