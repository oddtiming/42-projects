#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);

int	main(void)
{
	int	i;
	int	*ptr1;
	int	**ptr2;
	int	***ptr3;
	int	****ptr4;
	int	*****ptr5;
	int	******ptr6;
	int	*******ptr7;
	int	********ptr8;
	int	*********ptr9;

	i = 1;
	ptr1 = &i;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;
	printf("This is value of nbr before : %d\n", i);
	ft_ultimate_ft(ptr9);
	printf("This is value of nbr now : %d\n", i);
}
