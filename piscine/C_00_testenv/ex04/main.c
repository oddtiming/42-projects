/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:07:50 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/07/12 17:56:12 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_is_negative(int n);

int	main(void)
{
	printf("Is -1 a negative or positive number?\n");
	ft_is_negative(-1);
	printf("\nWhat about 1, bruv?\n");
	ft_is_negative(1);
	printf("\nAlriiight, what about 0, then?\n");
	ft_is_negative(0);
	return (0);
}
