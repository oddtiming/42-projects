#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);

int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

size_t	get_trim_len(char const *s1, char const *set, size_t init_len)
{
	size_t	trim_len;
	
	trim_len = init_len;
	while (is_set(*s1, set))
	{
		s1++;
		trim_len--;
	}
	while (!is_set(*s1, set))
		s1++;
	while (is_set(*s1, set))
	{
		s1++;
		trim_len--;
	}
	return (trim_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	trim_len;
	char	*s_trim;

	s1_len = ft_strlen(s1);
	trim_len = get_trim_len(s1, set, s1_len) + 1;
	s_trim = malloc(trim_len);
	while (is_set(*s1, set))
		s1++;
	while (trim_len)
	{
		*s_trim = *s1++;
		trim_len--;
	}
	*s_trim++ = 0;
	return (s_trim - trim_len);
}
