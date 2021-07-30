int	ft_sqrt(int nb)
{
	int	sqrt1;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	sqrt1 = nb/2;
	while (nb / sqrt1 < sqrt1)
	{
		sqrt1--;
	}
	if (nb % sqrt1 == 0)
		return (sqrt1);
	else
		return (0);
}
