int	ft_iterative_power(int nb, int power)
{
	int	value;

	value = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	while (--power > 0)
		value = value * nb;
	return (value);
}
