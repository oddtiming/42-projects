int	ft_sqrt (int nb)
{
	int	i;
	
	i = 0;
	if (nb > 0)
	{
		while (i * i <= nb)
		{
			if (i * i != nb)
				i++;
			else
				return (i);
		}
		return (0);
	}
	else
		return (0);
}
