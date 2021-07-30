int	ft_strlen(char *str);

char	*ft_strcat(char *dest, char *src)
{
	int	index_dest;
	int	index_src;

	index_src = 0;
	index_dest = ft_strlen(dest);
	while (src[index_src] != '\0')
	{
		dest[index_dest] = src[index_src];
		index_dest++;
		index_src++;
	}
	dest[index_dest] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
