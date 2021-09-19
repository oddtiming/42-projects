/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:10:09 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/16 19:38:50 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *) s;
	while (*ptr && n--)
	{
		if (*ptr == (char) c)
			return (ptr);
		ptr++;
	}
	if (c == 0 && *ptr == 0)
		return (ptr);
	return (NULL);
}
