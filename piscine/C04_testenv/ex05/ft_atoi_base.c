int	sign_of_int(char *str);
int	baseSize(char *base);
int	is_base(char c, char *base, int *base_order);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	value;
	int	base_size;
	int	base_order;

	i = 0;
	value = 0;
	base_order = 10;
	base_size = baseSize(base);
	if (base_size <= 1)
		return (0);
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (is_base(str[i], base, &base_order) >= 0)
	{
		value = value * base_order + is_base(str[i], base, &base_order);
		i++;
	}
	return (sign_of_int(str) * value);
}

int	is_base(char c, char *base, int *base_order)
{
	int	i;
	int	base_pos;

	i = -1;
	base_pos = -1;
	while (base[++i] != 0)
		if (c == base[i])
			base_pos = i;
	if (base_pos < 10)
		*base_order = 10;
	else if (base_pos >= 10)
		*base_order = 100;
	if (base_pos > 100)
		*base_order = 1000;
	return (base_pos);
}

int	baseSize(char *base)
{
	int		index;
	char	compare;
	int		j;

	index = 0;
	while (base[index] != '\0')
	{
		compare = base[index];
		j = (index + 1);
		if ((base[index] == '+' || base[index] == '-')
			|| base[index] == 31 || (base[index] > 8 && base[index] < 14))
			return (0);
		while (base[j] != '\0')
		{
			if (compare == base[j])
				return (0);
			j++;
		}
		index++;
	}
	return (index);
}

int	sign_of_int(char *str)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign);
}
