/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:07:04 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/30 08:19:59 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//Returns the number of chars until the char c is hit. Works with c == 0
size_t	strlen_c(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i])
		i++;
	if (!c)
		return (i);
	if (s[i] != c)
		return (0);
	else
		return (i + 1);
}

//Slightly modified version from the libft where the dest is freed
char	*ft_strjoin_free(char *s1, char const *s2, size_t n)
{
	size_t	tot_len;
	char	*s_joined;
	size_t	i;

	i = 0;
	tot_len = strlen_c(s1, 0) + strlen_c((char *)s2, 0) + 1;
	s_joined = malloc(tot_len);
	if (!s_joined)
		return (NULL);
	if (s1 || s1[i])
	{
		while (s1[i] && i < n)
			*s_joined++ = s1[i++];
		if (s1[0])
			free (s1);
	}
	i = 0;
	if (s2)
	{
		while (s2[i] && i < n)
			*s_joined++ = s2[i++];
	}
	*s_joined++ = 0;
	return (s_joined - tot_len);
}
/*
char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src)
		return (dest);
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
*/