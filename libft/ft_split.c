/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:05:51 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/26 15:51:21 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const s, char const c)
{
	if (s == c && c)
		return (1);
	return (0);
}

static size_t	get_chunk_len(char const *s, char c)
{
	size_t	len;

	if (!c)
		return (ft_strlen(s));
	len = 0;
	while (!is_set(s[len], c) && s[len])
		len++;
	return (len);
}

static size_t	get_nb_chunks(char const *s, char const c)
{
	size_t	nb_chunks;
	int		is_chunk;

	nb_chunks = 0;
	if (!*s)
		return (nb_chunks);
	if (!is_set(*s++, c))
		is_chunk = 1;
	while (*s)
	{
		if (!is_set(*s, c))
			is_chunk = 1;
		else
			is_chunk = 0;
		if (is_chunk == 0 && !is_set(*(s - 1), c))
			nb_chunks++;
		s++;
	}
	if (is_chunk == 1)
		nb_chunks++;
	return (nb_chunks);
}

static void	ft_free_split(char **arr_split)
{
	while (*arr_split)
	{
		free(*arr_split);
		arr_split++;
	}
}

char	**ft_split(char const *s, char const c)
{
	size_t	nb_chunks;
	char	**arr_split;
	size_t	i;
	size_t	chunk_len;

	i = 0;
	if (!s)
		return (NULL);
	nb_chunks = get_nb_chunks(s, c);
	arr_split = malloc((nb_chunks + 1) * sizeof(char *));
	if (!arr_split)
		return (NULL);
	while (i < nb_chunks)
	{
		while (is_set(*s, c))
			s++;
		chunk_len = get_chunk_len(s, c);
		arr_split[i] = ft_substr(s, 0, chunk_len);
		if (!arr_split[i])
			ft_free_split(arr_split);
		i++;
		s += chunk_len;
	}
	arr_split[i] = NULL;
	return (arr_split);
}
