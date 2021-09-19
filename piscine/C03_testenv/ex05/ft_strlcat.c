#include <stdio.h>
unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	strlen;

	i = 0;
	strlen = ft_strlen(dest);
	if (size < strlen)
		return (strlen + size + 1);
	while (src[i] != 0 && i + strlen < size - 1)
	{
		dest[i + strlen] = src[i];
		i++;
	}
	dest[i + strlen] = 0;
	while (src[i] != 0)
		i++;
	return (i + strlen);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
