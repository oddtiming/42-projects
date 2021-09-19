/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:35:49 by cwan-chu          #+#    #+#             */
/*   Updated: 2021/07/29 11:35:51 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	ft_celilen(int size, char **strs, char *sep)
{
	int	i;
	int	ln;

	i = 0;
	ln = 0;
	while (i < size)
	{
		ln = ln + ft_strlen(strs[i]);
		i++;
	}
	ln = ln + (size - 1) * ft_strlen(sep) + 1;
	return (ln);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		length;

	if (size == 0)
	{
		string = (char *)malloc (sizeof (char));
		*string = 0;
		return (string);
	}
	string = (char *)malloc (ft_celilen(size, strs, sep) * sizeof(char));
	if (!string)
		return (0);
	*string = 0;
	length = 0;
	while (length < size)
	{
		ft_strcat(string, strs[length]);
		if (length < size - 1)
			ft_strcat(string, sep);
		length++;
	}
	return (string);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
