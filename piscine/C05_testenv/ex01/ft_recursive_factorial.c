int	ft_recursive_factorial(int nb)
{
	int	fact;

	fact = 0;
	if (nb < 2 && nb >= 0)
		return (1);
	if (nb > 0)
		fact = nb * ft_recursive_factorial(nb - 1);
	return (fact);
}
