#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	src[50];
	char	*dest;

	strcpy(src, "ballteflon");
	dest = src;
	puts(src);
	puts(dest);
	memmove(src + 3, src, 5);
	puts(src);
	puts(dest);
	
}
