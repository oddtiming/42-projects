#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	total_length;

	i = 0;
	total_length = ft_strlen(src) + ft_strlen(dst);
	while (*dst)
		dst++;
	while (i < dstsize && *(src + i))
	{
		*dst++ = *(src + i);
		i++;
	}
	if (*(src + i) == 0)
		*dst = 0;
	else if (dstsize)
		*(dst - 1) = 0;
	return (total_length);
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

	strcpy(src, "this is to be added");
	strcpy(dest, "incomplete sentence");
	printf("This is the src string : '%s'\n", src);
	printf("This is the dest string : '%s'\n", dest);
	int i = strlcat(dest, src, 50);
	printf("This is the strlcatted dest string : '%s'\n", dest);
	printf("return value = %d\n", i);

	//reset the dest
	strcpy(dest, "incomplete sentence");
	printf("reset dest : '%s'\n", dest);
	i = ft_strlcat(dest, src, 50);
	printf("This is the strlcatted dest string : '%s'\n", dest);
	printf("return value = %d\n", i);

}
