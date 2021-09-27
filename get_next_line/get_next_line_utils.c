/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:10:20 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/27 13:11:30 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tot_len;
	char	*s_joined;

	tot_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s_joined = malloc(tot_len);
	if (!s_joined)
		return (NULL);
	if (s1)
	{
		while (*s1)
			*s_joined++ = *s1++;
	}
	if (s2)
	{
		while (*s2)
			*s_joined++ = *s2++;
	}
	*s_joined++ = 0;
	return (s_joined - tot_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	if (src)
	{
		while (src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src)
	{
		while (src[i] != 0 && i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = 0;
	return (dest);
}
