#include <stdio.h>
//int		*ft_atoi_base(char *nbr, char *base_from, int radix);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main()
{
	char *str8 = "03164572";
	char *str16 = "-ab59f";
	char *base8 = "01234567";
	char *base16 = "0123456789abcdef";
	char *base2 = "01";

	printf("nbr = '%s'\nbase_from = '%s'\nbase_to = '%s'\n", str8, base8, base16);
//	printf("atoi = %d\n", *ft_atoi_base(str8, base8, base_size(base8)));
	printf("Converted base = '%s'\n", ft_convert_base(str8, base8, base16));
	printf("(Should be	 'ce97a')\n\n");

	printf("nbr = '%s'\nbase_from = '%s'\nbase_to = '%s'\n", str8, base8, base2);
//	printf("atoi = %d\n", *ft_atoi_base(str8, base8, base_size(base8)));
	printf("Converted base = '%s'\n", ft_convert_base(str8, base8, base2));
	printf("(Should be	 '11001110100101111010')\n\n");

	printf("nbr = '%s'\nbase_from = '%s'\nbase_to = '%s'\n", str16, base16, base8);
//	printf("atoi = %d\n", *ft_atoi_base(str16, base16, base_size(base16)));
	printf("Converted base = '%s'\n", ft_convert_base(str16, base16, base8));
	printf("(Should be	 '-2532637')\n");
}
