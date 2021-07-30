/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 09:09:17 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/07/20 15:41:22 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	*src = {"123 567 90aa!!"};
	char	dest[100];
	int		n;
	int i = -1;

	printf("This is the test string : %s\n", src);
	n = 0;
	ft_strncpy(dest, src, n);
	printf("This is your destination string for n = %d: %s\n", n, dest);
	strncpy(dest, src, n);
	printf("This is strncpy's destination string for n = %d: %s\n", n, dest);
	n = 5;
	ft_strncpy(dest, src, n);
	printf("This is the destination string for n = %d: %s\n", n, dest);
	strncpy(dest, src, n);
	printf("This is strncpy's destination string for n = %d: %s\n", n, dest);
	printf("test for null termination");
	while (i++ < 100)
		printf("%c ", dest[i]);
	n = 18;
	ft_strncpy(dest, src, n);
	printf("This is the destination string for n = %d: %s\n", n, dest);
	printf("Is it null terminated ? : ");
	if (dest[strlen(src)] == '\0')
		printf("Heck ya, boi\n");
	else
		printf("You done fucked up...\n");
	strncpy(dest, src, n);
	printf("This is strncpy's destination string for n = %d: %s\n", n, dest);
	
	return (0);
}
