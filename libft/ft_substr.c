/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:51:42 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/19 12:01:38 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

/*
* Allocates (with malloc(3)) and returns a substringfrom the string ’s’.
* The substring begins at index ’start’ and is of maximum size ’len’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;

	s_len = ft_strlen(s + start);
	if (s_len < len)
		len = s_len;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	substr[len] = 0;
	while (len--)
		substr[len] = s[start + len];
	return (substr);
}
//Q : should the substr handle cases where start is passed the end of string?
//oui
