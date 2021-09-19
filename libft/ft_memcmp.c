/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:33:16 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/15 19:33:17 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *) s1;
	ptr2 = (char *) s2;
	while (n-- > 1)
	{
		if (*ptr1 != *ptr2)
			break ;
		ptr1++;
		ptr2++;
	}
	if ((unsigned char) *ptr1 > (unsigned char) *ptr2)
		return ((int) *ptr2 - (int) *ptr1);
	else if ((unsigned char) *ptr1 < (unsigned char) *ptr2)
		return ((int) *ptr1 - (int) *ptr2);
	return (0);
}
