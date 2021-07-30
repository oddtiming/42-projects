/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:24:40 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/07/29 16:30:57 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int		ft_strlen(char *str);
int		count_len(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;
	char	*str_joined;

	total_len = count_len(size, strs, sep) + 1;
	str_joined = (char *)malloc((total_len) * sizeof(*str_joined));
	i = 0;
	if (!str_joined)
		return (0);
	if (size < 1)
	{
		str_joined[i] = 0;
		return (str_joined);
	}
	while (i < size)
	{
		str_joined = ft_strcat(str_joined, strs[i]);
		if (i < size - 1)
			str_joined = ft_strcat(str_joined, sep);
		i++;
	}
	str_joined[total_len] = 0;
	return (str_joined);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index_dest;
	int	index_src;

	index_src = 0;
	index_dest = ft_strlen(dest);
	while (src[index_src] != '\0')
	{
		dest[index_dest] = src[index_src];
		index_dest++;
		index_src++;
	}
	dest[index_dest] = '\0';
	return (dest);
}

int	count_len(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += ft_strlen(sep);
		i++;
	}
	return (total_len);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
