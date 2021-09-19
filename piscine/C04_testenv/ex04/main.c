#include <stdio.h>
#include <limits.h>
void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	char *str1 = "0123456789";
	char *str2 = "01";
	char *str3 = "0123456789abcdef";
	char *str4 = "01234567";
	char *str5 = "qwertyuiopasdfghjkl";
	int nb = 1000;

	printf("Base = '%s'\nnb = %d\nYour function prints: \n", str1, nb);
	ft_putnbr_base(nb, str1);
	printf("\n\nBase = '%s'\nnb = %d\nYour function prints: \n", str2, nb);
	ft_putnbr_base(nb, str2);
	printf("\n\nBase = '%s'\nnb = %d\nYour function prints: \n", str3, nb);
	ft_putnbr_base(nb, str3);
	printf("\n\nBase = '%s'\nnb = %d\nYour function prints: \n", str4, nb);
	ft_putnbr_base(nb, str4);
	printf("\n\nBase = '%s'\nnb = %d\nYour function prints: \n", str5, nb);
	ft_putnbr_base(nb, str5);
	printf("\n");
}
