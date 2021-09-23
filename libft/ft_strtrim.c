/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:59:25 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/22 20:39:43 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	get_trim_len(char const *s1, char const *set, size_t init_len)
{
	size_t	trim_len;

	trim_len = init_len;
	while (is_set(*s1, set))
	{
		s1++;
		trim_len--;
	}
	while (!is_set(*s1, set))
		s1++;
	while (is_set(*s1, set))
	{
		s1++;
		trim_len--;
	}
	return (trim_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	trim_len;
	size_t	i;
	char	*s_trim;

	i = 0;
	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	trim_len = get_trim_len(s1, set, s1_len) + 1;
	s_trim = malloc(trim_len);
	if (!s_trim)
		return (NULL);
	while (is_set(*s1, set))
		s1++;
	while (i < trim_len)
	{
		s_trim[i] = s1[i];
		i++;
	}
	s_trim[i] = 0;
	return (s_trim);
}
