/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:28:44 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/07/29 19:39:37 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int		base_size(char *base);
int		exp_calc(int nb, int power);
int		log_calc(int value, int radix);
int		*ft_atoi_base(char *nbr, char *base_from, int radix);
char	*ft_itoa_base(int nb, char *base_to, int radix);

int	abs(int nb)
{
	if (nb >= 0)
		return (nb);
	return (-nb);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	radix_from;
	int	radix_to;
	int	*nb;

	radix_from = base_size(base_from);
	radix_to = base_size(base_to);
	nb = ft_atoi_base(nbr, base_from, radix_from);
	if (nb == NULL || radix_to < 2 || radix_from < 2)
		return (NULL);
	return (ft_itoa_base(*nb, base_to, radix_to));
}

char	*ft_itoa_base(int nb, char *base_to, int radix)
{
	char	*itoa;
	int		log;
	int		i;
	int		exp;

	i = 0;
	log = log_calc(abs(nb), radix);
	if (nb < 0)
	{	
		itoa = (char *)malloc((log + 2) * sizeof(*itoa));
		itoa[i++] = '-';
		nb = -nb;
	}
	else
		itoa = (char *)malloc((log + 1) * sizeof(*itoa));
	while (log-- > 0)
	{
		exp = exp_calc(radix, log);
		itoa[i++] = base_to[nb / exp];
		nb = nb - (nb / exp) * exp;
	}
	itoa[i] = 0;
	return (itoa);
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
