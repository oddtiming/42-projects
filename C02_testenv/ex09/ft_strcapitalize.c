int		isAlphanum(char c);
int		isLowercase(char c);
void	ft_strlowcase(char *str);

char	*ft_strcapitalize(char	*str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (isAlphanum(str[i]))
		{	
			if (isLowercase(str[i]) && (!isAlphanum(str[i - 1]) || i == 0))
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

int	isAlphanum(char c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

int	isLowercase(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	else
		return (0);
}

void	ft_strlowcase(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}
