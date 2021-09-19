#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*src != '\0' && i < dstsize)
	{
		*dst++ = *(src + i);
		i++;
	}
	if (i < dstsize)
		*dst = 0;
	else if (dstsize)
		*(dst - 1) = 0;
	printf("***inside the ft_strlcpy, ft_strlen(src) = %lu***\n\n", ft_strlen(src));
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int main(void)
{
	char	dest[50];
	char	src[50];

	strcpy(src, "this is the test string");
	printf("This is the src string : '%s'\n", src);
	int i = strlcpy(dest, src, 50);
	printf("This is the dest string for dstsize = 50: '%s'\n", dest);
	printf("return value = %d\n", i);
	
	printf("strlen(src) = %lu\nft_strlen(src) = %lu\n\n", strlen(src), ft_strlen(src));

	//reset the dest
	strcpy(dest, "");
	printf("reset dest : '%s'\n", dest);
	i = ft_strlcpy(dest, src, 50);
	printf("This is the dest string for dstsize = 50: '%s'\n", dest);
	printf("return value = %d\n", i);

}
