#include <stdio.h>
#include <string.h>
int	base_size(char *base);
int	is_base(char c, char *base);
char	*ft_strcpy(char *src);
//NOTE : SHOULD FIT INSIDE AN INT
int ft_atoi_base(char *nbr, char *base_from)
{
	int	i;
	int	value;
	int	sign;
	int	size;

	i = 0;
	sign = 1;
	value = 0;
	size = base_size(base_from);
	while (nbr[i] == 32)
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			value *= -1;
		i++;
	}
	while (is_base(nbr[i], base_from) != -1)
	{
		value = value * size + is_base(nbr[i], base_from);
		i++;
	}
	return (sign * value);
}

int	is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (i < base_size(base))
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	base_size(char *base)
{
	int		i;
	int		j;

	i = -1;
	while (base[++i])
	{
		j = i;
		while (base [++j])
			if (base[i] == base[j])
				return (0);
		if (base[i] < 32 || base[i] == '-' || base[i] == '+')
			return (0);
	}
	return (i);
}

int	main(void)
{
//	char	*bases[4] = {"0123456789abcdef", "tes", "+012", "123 456"};


//	int		size = 4;
	char *str1 = "0123456789";
	char *str2 = "poneyvif";
	char *str3 = "0123456789abcdef";
	char *str4 = "0123456789abcdef";
	char *str5 = " +---+1234 4";

	printf("str = '%s'\nbase = '%s'\nYour function returns: %d\n\n", str5, str1, ft_atoi_base(str5, str1));
	char *str6 = "oevf";
	printf("str = '%s'\nbase = '%s'\nYour function returns: %d\n\n", str6, str2, ft_atoi_base(str6, str2));
	char *str7 = "abeef";
	printf("str = '%s'\nbase = '%s'\nYour function returns: %d\n\n", str7, str3, ft_atoi_base(str7, str3));
	char *str8 = "ab908";
	printf("str = '%s'\nbase = '%s'\nYour function returns: %d\n\n", str8, str4, ft_atoi_base(str8, str4));
	printf("str = '%s'\nbase = '%s'\nYour function returns: %d\n\n", str6, str4, ft_atoi_base(str6, str4));
	//for(int i = 0; i < size; i++)
//		printf("String = '%s', and base_size = '%d'\n\n", bases[i], base_size(bases[i]));
//	printf("Test for strcpy . orig '%s' copy '%s'\n\n", bases[0], ft_strcpy(bases[0]));
}
