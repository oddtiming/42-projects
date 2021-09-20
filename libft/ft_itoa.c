/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:34:58 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/20 13:38:47 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int	power_calc(int base, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (base * power_calc(base, power - 1));
}

static int	get_a_len(int n)
{
	int	a_len;

	a_len = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		a_len++;
	}
	return (a_len);
}

//fct is one line too long, and malloc should be split in a_len + 1 if n >= 0;
char	*ft_itoa(int n)
{
	int		a_len;
	int		i;
	char	*n_to_a;
	
	i = 0;
	a_len = get_a_len(n);
	n_to_a = malloc(a_len + 2);
	if (!n_to_a)
		return (NULL);
	if (n < 0)
	{
		n_to_a[i++] = '-';
		if (n == INT_MIN)
		{
			n_to_a[i++] = '2';
			n = n % power_calc(10, --a_len);
		}
		n *= -1;
	}
	while (a_len--)
	{
		n_to_a[i++] = (n / power_calc(10, a_len)) + '0';
		n = n % power_calc(10, a_len);
	}
	n_to_a[i] = 0;
	return (n_to_a);
}
