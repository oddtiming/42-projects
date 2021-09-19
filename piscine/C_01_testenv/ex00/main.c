#include <unistd.h>
#include <stdio.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int	i;
	int	*i_ptr;

	i = 1;
	i_ptr = &i;
	printf("Ça c'est la valeur, mais fuck that: %d \n", i);
	ft_ft(i_ptr);
	printf("Ça c'est la valeur d'ast'heure, yesseur: %d \n", i);
	return (0);
}
