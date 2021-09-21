/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:05:51 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/19 12:35:37 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(char const*s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

static int	is_set(char const s, char const c)
{
	if (s == c && c)
		return (1);
	return (0);
}

static size_t	get_chunk_len(char const **s, char c)
{
	size_t	len;

	if (!c)
		return (ft_strlen(*s));
	len = 0;
	while (is_set(**s, c) && c)
		*s += 1;
	while (!is_set(**s, c) && c)
	{
		len++;
		*s += 1;
	}
	while (is_set(**s, c) && c)
		*s += 1;
	return (len);
}

static size_t	get_nb_chunks(char const *s, char const c)
{
	size_t	nb_chunks;
	int		is_chunk;

	nb_chunks = 0;
	if (!*s)
		return (nb_chunks);
	else if (!is_set(*s++, c))
		is_chunk = 1;
	while (*s)
	{
		if (!is_set(*s, c))
			is_chunk = 1;
		else if (is_set(*s, c))
			is_chunk = 0;
		if (is_chunk == 0 && !is_set(*(s - 1), c))
			nb_chunks++;
		s++;
	}
	if (is_chunk == 1)
		nb_chunks++;
	return (nb_chunks);
}

char	**ft_split(char const *s, char const c)
{
	size_t	nb_chunks;
	char	**arr_split;
	size_t	i;

	i = 0;
	nb_chunks = get_nb_chunks(s, c);
	arr_split = malloc((nb_chunks + 1) * sizeof(char *));
	if (!arr_split)
		return (NULL);
	while (i < nb_chunks)
	{
		while (is_set(*s, c))
			s++;
		arr_split[i] = ft_substr(s, 0, get_chunk_len(&s, c));
		i++;
	}
	arr_split[i] = NULL;
	return (arr_split);
}