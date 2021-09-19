#include <stdio.h>
#include <string.h>
unsigned int ft_strlcat(char*dest, char*src, unsigned int size);

int	main(void)
{
	printf("This is with my ft_strlcat : \n");
	char src[10] = {"1234567"};
	char dest[8];
	unsigned int dest_size;
	dest_size = 5;	
	strlcat(dest, src, dest_size);
	printf("this is the dest : %s\n", dest);
	printf("this is th return : %d\n",ft_strlcat(dest,src,dest_size));	
	printf("This is with the real strlcat : \n");
	char src2[10] = {"1234567"};
	char dest2[8];
	unsigned int dest_size2;
	dest_size2 = 5;	
	strlcat(dest2, src2, dest_size2);
	printf("this is the dest : %s\n", dest2);
	printf("this is th return : %lu\n",strlcat(dest2,src2,dest_size2));	
	
	return (0);
}
