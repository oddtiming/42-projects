/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:51:31 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/07/28 10:51:32 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
unsigned int	ft_size(int min, int max);

int	*ft_range(int min, int max)
{
	unsigned int	index;
	unsigned int	size;
	int				*tab;

	index = 0;
	size = ft_size(min, max);
	tab = (int *)malloc((size) * sizeof(int));
	if (size == 0)
		return (NULL);
	while (index < size)
	{
		tab[index] = min;
		min++;
		index++;
	}
	return (tab);
}

unsigned int	ft_size(int min, int max)
{
	unsigned int	size;

	size = 0;
	while (min < max)
	{
		min++;
		size++;
	}
	return (size);
}
