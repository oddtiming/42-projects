int	ft_strlen(char *str);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index_src;
	unsigned int	index_dest;
	char			*destcpy;

	destcpy = dest;
	index_src = 0;
	index_dest = ft_strlen(dest);
	while (src[index_src] != '\0' && index_src < nb)
	{
		destcpy[index_dest] = src[index_src];
		index_dest++;
		index_src++;
	}
	destcpy[index_dest] = '\0';
	return (destcpy);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
