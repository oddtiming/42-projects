#include "ft_printf.h"
/*
char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	tot_len;
	char	*s_joined;
	int		i;

	i = 0;
	tot_len = strlen_c(s1, 0) + strlen_c((char *)s2, 0) + 1;
	s_joined = malloc(tot_len);
	if (!s_joined)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			*s_joined++ = s1[i++];
		free (s1);
	}
	if (s2)
		while (*s2)
			*s_joined++ = *s2++;
	*s_joined++ = 0;
	return (s_joined - tot_len);
}
*/