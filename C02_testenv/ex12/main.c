#include <stdio.h>
#include <string.h>
void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	char	*str;
	void	*ptr;

	str = "This is a test string with a total of 45 char";
	ptr = &str;
	printf("%s, size = %lu\n", str, strlen(str));
	printf("Address : %p\n", str);
	ft_print_memory(ptr);
	return (0);
}
