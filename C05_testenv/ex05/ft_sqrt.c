int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	sqrt = nb / 2;
	while (nb / sqrt < sqrt)
	{
		if (4 * (nb / sqrt) < sqrt)
			sqrt /= 2;
		else
			sqrt--;
	}
	if (sqrt * sqrt == nb)
		return (sqrt);
	else
		return (0);
}
