#include <stdio.h>
#include <stdlib.h>
int	base_size(char *base);
int	exp_calc(int nb, int power);
int	log_calc(int value, int radix);

char	*ft_itoa_base(int nb, char *base_to)
{
	char	*itoa;
	int		log;
	int		radix;
	int		i;
	int	exp;
	char number; //TO REMOVE

	i = 0;
	radix = base_size(base_to);
	log = log_calc(nb, radix);
	itoa = (char *)malloc((log + 1) * sizeof(*itoa));
	printf("log = %d; radix = %d\n", log, radix); //TO REMOVE
	while (log > 0)
	{
		exp = exp_calc(radix, log - 1);
		printf("%d ^ %d =  %d\n%d - %d = %d\n", radix, log - 1, exp, nb, exp, nb);
 		number = base_to[nb / exp]; //TO REMOVE
		itoa[i] = number; //TO FIX
		printf("Number #%d = %c\n", i, number);
		nb = nb - (nb / exp) * exp;
		i++;
		log--;
	}
	itoa[i] = 0;
	return(itoa);
}

int	exp_calc(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * exp_calc(nb, power - 1));
}

int	log_calc(int value, int radix)
{
	int	counter;
	int	radix_pow;

	radix_pow = radix;
	counter = 1;
	while (radix_pow <= value)
	{
		radix_pow *= radix;
		counter++;
	}
	return (counter);
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

int main()
{
	char *base2 = "0123456789abcdef";
	int i = 11000;

	printf("Conversion of %d to base '%s' is '%s'\n", i, base2, ft_itoa_base(i, base2));

}
