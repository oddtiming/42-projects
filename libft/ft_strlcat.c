/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:53:35 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/15 16:53:36 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	total_length;

	i = 0;
	total_length = ft_strlen(src) + ft_strlen(dst);
	while (*dst)
		dst++;
	while (i < dstsize && *(src + i))
	{
		*dst++ = *(src + i);
		i++;
	}
	if (*(src + i) == 0)
		*dst = 0;
	else if (dstsize)
		*(dst - 1) = 0;
	return (total_length);
}	
