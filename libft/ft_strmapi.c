/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:34:09 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/20 12:30:22 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*f_s;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	f_s = malloc(s_len + 1);
	if (!f_s)
		return (NULL);
	while (i < s_len)
	{
		f_s[i] = (*f)(32, s[i]);
		i++;
	}
	f_s[i] = 0;
	return (f_s);
}
