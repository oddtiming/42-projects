/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:10:45 by cwan-chu          #+#    #+#             */
/*   Updated: 2021/07/27 18:10:51 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*string;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	string = (char *) malloc (sizeof (char) * (len + 1));
	if (!string)
		return (NULL);
	else
	{
		while (src [i])
		{
			string[i] = src [i];
			i++;
		}
		string [i] = '\0';
		return (string);
	}
}
