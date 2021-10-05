#include "libft.h"

size_t	strlen_c(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i])
		i++;
	if (!c)
		return (i);
	if (s[i] != c)
		return (0);
	else
		return (i + 1);
}