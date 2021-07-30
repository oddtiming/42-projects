/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 09:09:17 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/07/13 19:53:22 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char			*src = {"There are 18 chars"};
	char			dest[125];
	unsigned int	n;

	n = 30;
	printf("This is the test string : '%s'\n", src);
	printf("size given by your fct: %u\n", ft_strlcpy(dest, src, n));
	printf("and the modified string: '%s'\n", dest);
	printf("size given by strlcpy: %lu\n", strlcpy(dest, src, n));
	printf("and the modified string: '%s'\n\n", dest);
	n = 5;
	printf("size given by your fct: %u\n", ft_strlcpy(dest, src, n));
	printf("and the modified string: '%s'\n", dest);
	printf("size given by strlcpy: %lu\n", strlcpy(dest, src, n));
	printf("and the modified string: '%s'\n\n", dest);
	n = 1;
	printf("size given by your fct: %u\n", ft_strlcpy(dest, src, n));
	printf("and the modified string: '%s'\n", dest);
	printf("size given by strlcpy: %lu\n", strlcpy(dest, src, n));
	printf("and the modified string: '%s'\n\n", dest);
	n = 0;
	printf("size given by your fct: %u\n", ft_strlcpy(dest, src, n));
	printf("and the modified string: '%s'\n", dest);
	printf("size given by strlcpy: %lu\n", strlcpy(dest, src, n));
	printf("and the modified string: '%s'\n\n", dest);
	n = -6;
	printf("size given by your fct: %u\n", ft_strlcpy(dest, src, n));
	printf("and the modified string: '%s'\n", dest);
	printf("size given by strlcpy: %lu\n", strlcpy(dest, src, n));
	printf("and the modified string: '%s'\n\n", dest);
	return (0);
}
