/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:02:31 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/07/29 19:35:32 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	is_base(char c, char *base);

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
		if (base[i] <= 32 || base[i] == '-' || base[i] == '+')
			return (0);
	}
	return (i);
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

int	sign_of_int(char *str)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign);
}

int	*ft_atoi_base(char *nbr, char *base_from, int radix)
{
	int		i;
	long	value;
	int		sign;
	int		*ptr_value;

	i = 0;
	sign = sign_of_int(nbr);
	value = 0;
	while (nbr[i] == 32)
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (is_base(nbr[i], base_from) != -1)
	{
		value = value * radix + is_base(nbr[i], base_from);
		i++;
	}
	if (value > 2147483647 || value < -2147483648)
		return (NULL);
	sign *= value;
	ptr_value = &sign;
	return (ptr_value);
}
