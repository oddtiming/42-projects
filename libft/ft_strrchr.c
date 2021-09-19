/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:19:44 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/15 17:20:05 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	needle;

	ptr = NULL;
	needle = (char) c;
	while (*s)
	{
		if (*s == needle)
			ptr = (char *) s;
		s++;
	}
	if (needle == '\0')
		return ((char *) s);
	return (ptr);
}
