#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_strdup.c"

int	main (void)
{
	char	*string;

	string = "I love potato";
	printf ("The string is: %s\n", string);
	printf ("The result is: %s\n", ft_strdup(string));
	
	string = "I am a potato girl";
	printf ("The string is: %s\n", string);
	printf ("The result is: %s\n", ft_strdup(string));
	
	string = "Everyone loves potato. I kinda do not trust you if you do not.";
	printf ("The string is: %s\n", string);
	printf ("The result is: %s\n", ft_strdup(string));
}
