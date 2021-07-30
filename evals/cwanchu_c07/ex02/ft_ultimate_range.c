/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:32:28 by cwan-chu          #+#    #+#             */
/*   Updated: 2021/07/28 18:32:30 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	i;

	i = 0;
	if (min >= max)
	{
		array = NULL;
		return (0);
	}
	array = (int *)malloc((max - min) * sizeof (int));
	if (array == 0)
		return (0);
	else
	{
		while (i + min < max)
		{
			array[i] = min + i;
			i++;
		}
	}
	*range = array;
	return (max - min);
}
