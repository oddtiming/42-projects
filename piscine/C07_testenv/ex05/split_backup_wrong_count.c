/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:24:28 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/07/29 12:53:20 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_strs(char *str, char *set)
{
	int	i;
	int	counter;
	int	is_body;

	i = 0;
	counter = 0;
	is_body = 0;
	while (str[i])
	{
		if (!is_set(str[i], set) && is_body == 0)
		{
			is_body = 1;
			counter++;
		}
		if (is_set(str[i], set))
			is_body = 0;
		i++;
	}
	return (counter);
}

char **ft_split(char *str, char *charset)
{
	int		i;
	int		nb_chunks;
	char	**strs;

	i = 0;
	nb_chunks = count_strs(str, charset);
}
