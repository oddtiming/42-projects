/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:26:51 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/15 20:34:27 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	if (*needle == 0)
		return ((char *) haystack);
	while (len-- && *haystack)
	{
		i = 0;
		while (needle[i] == haystack[i] && needle[i] && len - i + 1)
			i++;
		if (needle[i] == 0)
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
