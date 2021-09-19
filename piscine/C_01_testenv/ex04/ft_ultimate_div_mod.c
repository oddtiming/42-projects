void	ft_ultimate_div_mod(int *a, int *b)
{
	int	aStore;
	int	bStore;
	int	divStore;
	int	modStore;

	aStore = *a;
	bStore = *b;
	divStore = aStore / bStore;
	modStore = aStore % bStore;
	*a = divStore;
	*b = modStore;
}
