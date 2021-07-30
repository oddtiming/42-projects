int	is_space(char c);

int	ft_atoi(char *src)
{
	int	index;
	int	value;
	int	sign;

	index = 0;
	value = 0;
	sign = 1;
	while (is_space(src[index]))
		index++;
	while (src[index] == '-' || src[index] == '+')
	{
		if (src[index] == '-')
			sign *= -1;
		index++;
	}
	while (src[index] >= '0' && src[index] <= '9')
	{
		value = 10 * value + src[index] - '0';
		index++;
	}
	return (sign * value);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
