#include <stdlib.h>
unsigned int	ft_strlen(char *str);
unsigned int	size_array(unsigned int size, char **strs, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	unsigned int	i;
	unsigned int	j;
	char			*strjoined;
	unsigned int	size_s;
	int				nb_seps;

	i = 0;
	nb_seps = 0;
	size_s = size_array((unsigned int)size, strs, sep);
	if (size > 0)
		size_s += (size - 1) * ft_strlen(sep) + 1;
	strjoined = (char *)malloc((size_s) * sizeof(char));
	while (i < size_s)
	{
		if (*strs[i - nb_seps * ft_strlen(sep)] == 0)
		{
			j = 0;
			while (j < ft_strlen(sep))
			{
				strjoined[i] = sep[j];
				i++;
				j++;
			}
		}
		strjoined[i] = *strs[i - nb_seps * ft_strlen(sep)];
	}
	strjoined[i] = 0;
	return (strjoined);
}

unsigned int	size_array(unsigned int size, char **strs, char *sep)
{
	unsigned int	size_array;
	unsigned int	null_counter;
	unsigned int	i;
	unsigned int	size_sep;

	i = 0;
	size_array = 0;
	size_sep = ft_strlen(sep);
	null_counter = 0;
	while (null_counter < size)
	{
		if (*strs[i] == 0)
			null_counter++;
		else
			size_array++;
	}
	return (size_array);
}

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
