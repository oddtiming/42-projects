/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:56:01 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/07/28 11:24:35 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
unsigned int	ft_size(int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	index;
	unsigned int	size;

	index = 0;
	size = ft_size(min, max);
	if (size == 0)
	{
		range = (NULL);
		return (0);
	}
	*range = (int *)malloc(size * sizeof(**range));
	if (*range == NULL)
		return (-1);
	while (index < size)
	{
		(*range)[index] = min;
		min++;
		index++;
	}
	return (size);
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
