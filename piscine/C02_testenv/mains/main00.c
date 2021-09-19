/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 09:09:17 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/07/15 12:01:49 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	*src = {"SUUUUUUH DUDE!?"};
	char	dest[100];
	int i;
	int len;

	i = 0;
	printf("This is the test string : %s\n", src);
	ft_strcpy(dest, src);
	printf("This is the destination string: %s\n", dest);
	len = strlen(src);
	printf("This is the length of the source: %d\n", len);
	len = strlen(dest);
	printf("And is the length of the dest: %d\n", len);
	return (0);
}
