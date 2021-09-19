int	ft_is_prime(int nb)
{
	int	divider;

	divider = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (divider < nb / divider && nb % divider != 0)
		divider++;
	if (nb % divider == 0)
		return (0);
	return (1);
}
