/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:24:28 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/07/29 20:07:19 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_strs(char *str, char *charset)
{
	int	i;
	int	counter;
	int	is_body;

	i = 0;
	counter = 0;
	is_body = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset) && is_body == 0)
		{
			is_body = 1;
			counter++;
		}
		if (is_charset(str[i], charset))
			is_body = 0;
		i++;
	}
	return (counter);
}

int	next_chunk_size(char *str, char *charset)
{
	int	i;
	int	is_body;
	int	counter;

	i = 0;
	is_body = 0;
	counter = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			is_body = 1;
			counter++;
		}
		if (is_body == 1 && is_charset(str[i], charset))
			return (counter);
		i++;
	}
	return (counter);
}

char	*get_next_chunk(char *dest, char **src, char *charset)
{
	int		i;
	int		is_body;

	i = 0;
	is_body = 0;
	while (**src)
	{
		if (!is_charset(**src, charset))
		{
			dest[i] = **src;
			i++;
			is_body = 1;
		}
		if (is_body == 1 && is_charset(**src, charset))
			break ;
		*src += 1;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		nb_chunks;
	char	**strs;
	int		chunk_len;

	i = 0;
	nb_chunks = count_strs(str, charset);
	strs = (char **)malloc((nb_chunks + 1) * sizeof(*strs));
	while (i < nb_chunks)
	{
		chunk_len = next_chunk_size(str, charset);
		strs[i] = (char *)malloc((chunk_len + 1) * sizeof(*strs[i]));
		strs[i] = get_next_chunk(strs[i], &str, charset);
		i++;
	}
	strs[i] = (char *)malloc(sizeof(*strs[i]));
	strs[i][0] = 0;
	return (strs);
}
