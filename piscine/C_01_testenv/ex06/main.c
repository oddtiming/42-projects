#include <stdio.h>
#include <string.h>
int	ft_strlen(char *c);

int	main(void)
{
	char	*c;
	char	empty[100];
	int		i;

	c = "patate poil lolol";
	i = ft_strlen(c);
	printf("The string is '%s'\n", c);
	printf("The length given by strlen fct is: %lu\n", strlen(c));
	printf("The one given by your fct is: %d\n", i);
	i = ft_strlen(empty);
	printf("Now the string is '%s'\n", empty);
	printf("The length given by strlen fct is: %lu\n", strlen(empty));
	printf("The one given by your fct is: %d\n", i);
	return (0);
}
