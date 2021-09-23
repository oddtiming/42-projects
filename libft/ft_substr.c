/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:51:42 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/22 20:20:06 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Allocates (with malloc(3)) and returns a substringfrom the string ’s’.
* The substring begins at index ’start’ and is of maximum size ’len’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	
	s_len = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) > start)
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
/*

//Nicolas COLOMER (Glagan)'s code
char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
*/