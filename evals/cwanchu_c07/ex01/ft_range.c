/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 20:05:24 by cwan-chu          #+#    #+#             */
/*   Updated: 2021/07/28 18:32:19 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	range = (int *)malloc((max - min) * sizeof (int));
	if (range == 0)
		return (0);
	else
	{
		while (i + min < max)
		{
			range[i] = min + i;
			i++;
		}
		return (range);
	}
}
