/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:01:11 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/15 19:01:56 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1 && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if ((unsigned char) s1[i] > (unsigned char) s2[i])
		return ((unsigned char) s2[i] - (unsigned char) s1[i]);
	else if ((unsigned char) s1[i] < (unsigned char) s2[i])
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}
