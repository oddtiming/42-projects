/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:38:12 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/23 10:13:47 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dupl;

	len = ft_strlen(s1) + 1;
	dupl = (char *)malloc(len);
	if (!dupl)
		return (NULL);
	while (len--)
		dupl[len] = s1[len];
	return (dupl);
}
