/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:11:10 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/15 17:11:12 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	needle;

	ptr = (char *) s;
	needle = (char) c;
	while (*ptr)
	{
		if (*ptr == needle)
			return (ptr);
		ptr++;
	}
	if (needle == '\0')
		return (ptr);
	return (NULL);
}
