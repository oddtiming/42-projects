/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:29:52 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/11/30 19:27:24 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	size_t	i;
	char	*s_joined;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i++])
		;
	while (s2[j++])
		;
	s_joined = malloc(i + j - 1);
	if (!s_joined)
		return (NULL);
	while (*s1)
		*s_joined++ = *s1++;
	while (*s2)
		*s_joined++ = *s2++;
	*s_joined = 0;
	return (s_joined - i - j + 2);
}

int main(void)
{
	printf("s1 = %s\ns2 = %s\nstr_joined = %s\n", "patate", "poil", ft_strjoin("patate", "poil"));
}
