#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int	count_strs(char *str, char *set);
int	is_set(char c, char *set);
char **ft_split(char *str, char *charset);

int main(void)
{
	char	*str1 = ":thiiis:is:a    : p long:test:";
	char	*sep = " :p";
	int	nb_chunks;
	char	**strs;
	int i;

	nb_chunks = count_strs(str1, sep);
	printf("str1 = '%s'\nsep = '%s'\nnumber of chunks = %u\n\n", str1, sep, nb_chunks);
	strs = ft_split(str1, sep);
	for (i = 0; i < nb_chunks; i++)
		printf("strs#%d : '%s'\n", i, strs[i]);
	printf("last one should be empty : '%s'\n", strs[i]);
}
/*
int	is_set(char c, char *set)
{
	int	i;

	i = -1;

	while (set[++i])
		if (c == set[i])
			return (i);
	return (-1);
}

int	count_strs(char *str, char *set)
{
	int	counter;
	int	i;
	int	is_body;

	i = 0;
	counter = 0;
	is_body = 0;
	while (str[++i])
	{
		if (is_set(str[i], set) == -1 && is_set(str[i - 1], set) >= 0)
			is_body = 1;
		if (is_set(str[i], set) && is_body == 1)
		{
			counter++;
			printf("char = %c\n", str[i]);
			is_body = 0;
		}
	}
	if (is_set(str[i - 1], set) == -1)
		return (counter - 1);
	return (counter);
}
*/
